# Website-Analytics

Distributed Lab test task. 

## Description

This console application analyzes user activity across two days using two CSV files.  
Each CSV contains rows in the format: `user_id,product_id,timestamp`.

The program identifies and prints the **user IDs** of those who:
- Were active on **both days**
- Visited at least **one new product page** on the second day that they hadn't visited on the first.

The data is stored in two `unordered_map<uint64_t, unordered_set<uint64_t>>` structures, representing users and the products they visited each day.

## Technologies
- **Language:** C++17  
- **Build system:** GNU Make on Ubuntu (Linux)  

## How to run
1. Clone the project to a folder on your device:
   
   ```bash
   https://github.com/kamawui/Website-Analytics.git
   ```
   
2. Navigate to the project folder:
   
   ```bash
   cd Website-Analytics
   ```
   
3. Compile the program:
   
   ```bash
   make
   ```
   
4. Run the program:
   ```bash
   ./website_analytics
   ```

## Usage
Run the program with two CSV file paths:: 
```bash
./website_analytics <day1.csv> <day2.csv>
```

Format of CSV data:
```
<user_id>,<product_id>,<timestamp>
```

Example:
```bash
111,101,2025-07-11T10:00:00
111,102,2025-07-11T10:05:00
112,201,2025-07-11T10:10:00
113,301,2025-07-11T10:15:00
114,401,2025-07-11T10:20:00
115,501,2025-07-12T10:30:00
```

By cloning the repository you also got **examples** folder with .csv files. You can test the program like that:
```bash
./website_analytics examples/day1.csv examples/day2.csv
```

## Example
Day 1:
```bash
111,101,2025-07-11T10:00:00
111,102,2025-07-11T10:05:00
112,201,2025-07-11T10:10:00
113,301,2025-07-11T10:15:00
```
Day 2:
```bash
111,102,2025-07-11T10:05:00
112,201,2025-07-12T10:10:00
112,202,2025-07-12T10:15:00
111,101,2025-07-12T10:05:00
113,301,2025-07-12T10:20:00
113,302,2025-07-12T10:25:00
111,103,2025-07-12T10:05:00
114,401,2025-07-11T10:20:00
```
<img width="1423" height="258" alt="{6E482CAE-91F2-418A-8177-3C5387EB2D8D}" src="https://github.com/user-attachments/assets/e61f5baf-bea9-4c9b-9985-43447dfcf036" />



## Efficiency and complexity
1) CSV parsing — O(N), N - number of lines in both files.
2) Pushing user to unordered map structure - O(1).
3) Checking if user from the second day had visited some page on the first day - O(1)
4) Comparing pages of user from the second day with first day pages - O(U), U - number of users of second day

In total:
O(N)

## Time to implement the task
Up to 4 hours.

