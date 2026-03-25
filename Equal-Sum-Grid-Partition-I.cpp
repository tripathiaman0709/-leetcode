1class Solution {
2public:
3    bool canPartitionGrid(vector<vector<int>>& v) {
4        int n = v.size();
5        int m = v[0].size();
6
7        vector<long long> row, col;
8
9        // Row sums
10        for(int i = 0; i < n; i++){
11            long long sum = 0;
12            for(int j = 0; j < m; j++){
13                sum += v[i][j];
14            }
15            row.push_back(sum);
16        }
17
18        // Column sums
19        for(int i = 0; i < m; i++){
20            long long sum = 0;
21            for(int j = 0; j < n; j++){
22                sum += v[j][i];
23            }
24            col.push_back(sum);
25        }
26
27        vector<long long> prerow(n), precol(m);
28
29        prerow[0] = row[0];
30        for(int i = 1; i < n; i++){
31            prerow[i] = prerow[i-1] + row[i];
32        }
33
34        precol[0] = col[0];
35        for(int i = 1; i < m; i++){
36            precol[i] = precol[i-1] + col[i];
37        }
38
39        long long rowtotal = prerow[n-1];
40        long long coltotal = precol[m-1];
41
42        // Check row partition
43        for(int i = 0; i < n-1; i++){
44            if(prerow[i] == rowtotal - prerow[i]){
45                return true;
46            }
47        }
48
49        // Check column partition
50        for(int i = 0; i < m-1; i++){
51            if(precol[i] == coltotal - precol[i]){
52                return true;
53            }
54        }
55
56        return false;
57    }
58};