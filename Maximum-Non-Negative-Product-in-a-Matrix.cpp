1class Solution {
2public:
3    #define mod 1000000007
4    int n, m;
5
6    vector<vector<pair<long long, long long>>> dp;
7    vector<vector<bool>> vis;
8
9    pair<long long,long long> solve(int i, int j, vector<vector<int>>& grid) {
10        if (i >= n || j >= m) {
11            return {LLONG_MIN, LLONG_MAX}; // invalid
12        }
13
14        if (i == n-1 && j == m-1) {
15            return {grid[i][j], grid[i][j]};
16        }
17
18        if (vis[i][j]) return dp[i][j];
19        vis[i][j] = true;
20
21        auto right = solve(i, j+1, grid);
22        auto down  = solve(i+1, j, grid);
23
24        long long val = grid[i][j];
25
26        long long maxi = LLONG_MIN;
27        long long mini = LLONG_MAX;
28
29        // process right
30        if (right.first != LLONG_MIN) {
31            maxi = max({maxi, right.first * val, right.second * val});
32            mini = min({mini, right.first * val, right.second * val});
33        }
34
35        // process down
36        if (down.first != LLONG_MIN) {
37            maxi = max({maxi, down.first * val, down.second * val});
38            mini = min({mini, down.first * val, down.second * val});
39        }
40
41        return dp[i][j] = {maxi, mini};
42    }
43
44    int maxProductPath(vector<vector<int>>& grid) {
45        n = grid.size();
46        m = grid[0].size();
47
48        dp.assign(n, vector<pair<long long,long long>>(m));
49        vis.assign(n, vector<bool>(m, false));
50
51        auto res = solve(0, 0, grid);
52
53        long long maxProd = res.first;
54
55        if (maxProd < 0) return -1;
56        return maxProd % mod;
57    }
58};