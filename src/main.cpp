#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <cstdint>
#include <string>
#include <fstream>
#include <sstream>

std::unordered_map<uint64_t, std::unordered_set<uint64_t>> parse_csv(std::string filename) {
	std::ifstream file(filename);

	if (!file.is_open()) {
		throw std::runtime_error("cannot open file " + filename);
	}

	std::unordered_map<uint64_t, std::unordered_set<uint64_t>> data;
	std::string line;

	size_t bad_rows = 0;

	while (std::getline(file, line)) {
		if (line.empty()) continue;

		std::stringstream ss(line);

		std::string user_id_str, product_id_str, timestamp;

		std::getline(ss, user_id_str, ',');
		std::getline(ss, product_id_str, ',');
		std::getline(ss, timestamp);

		try {
			uint64_t user_id = std::stoull(user_id_str);
			uint64_t product_id = std::stoull(product_id_str);
			data[user_id].insert(product_id);
		}
		catch (const std::exception& e) {
			bad_rows++;
		}
	}

	if (bad_rows > 0) {
		std::cerr << "Skipped " << bad_rows << " invalid rows in " << filename << std::endl;
	}

	return data;
}

int main(int argc, char* argv[]) {
	if (argc != 3) {
		std::cerr << "usage: ./website_analytics [csv_path1] [csv_path2]\n";
		return 1;
	}

	try {
		auto first_day = parse_csv(argv[1]);
		auto second_day = parse_csv(argv[2]);

		std::cout << "Users who were active on both days and on the second day visited the page they hadn't visited on the first day:\n";

		for (const auto& [user, products2] : second_day) {
			const auto user_iterator = first_day.find(user);

			if (user_iterator != first_day.end()) {
				const auto& products1 = user_iterator->second;

				for (const auto& product : products2) {
					if (products1.count(product) == 0) {
						std::cout << user << std::endl;
						break;
					}
				}
			}
		}
	}
	catch (const std::runtime_error& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
}