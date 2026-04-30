1class Solution {
2public:
3    int n, m;
4    vector<vector<vector<int>>> dp;
5
6    int solve(int i, int j, vector<vector<int>>& grid, int k) {
7        if (k < 0) return INT_MIN;
8        if (i >= n || j >= m) return INT_MIN;
9
10        if (dp[i][j][k] != -1) return dp[i][j][k];
11
12        int cost = 0, gain = 0;
13
14        if (grid[i][j] == 1) {
15            cost = 1;
16            gain = 1;
17        } else if (grid[i][j] == 2) {
18            cost = 1;
19            gain = 2;
20        }
21
22        if (k - cost < 0) return dp[i][j][k] = INT_MIN;
23
24        // destination
25        if (i == n - 1 && j == m - 1) {
26            return dp[i][j][k] = gain;
27        }
28
29        int right = solve(i, j + 1, grid, k - cost);
30        int down  = solve(i + 1, j, grid, k - cost);
31
32        int best = max(right, down);
33
34        if (best == INT_MIN)
35            return dp[i][j][k] = INT_MIN;
36
37        return dp[i][j][k] = gain + best;
38    }
39
40    int maxPathScore(vector<vector<int>>& grid, int k) {
41        n = grid.size();
42        m = grid[0].size();
43
44        dp.assign(n, vector<vector<int>>(m, vector<int>(k + 1, -1)));
45
46        int ans = solve(0, 0, grid, k);
47
48        return (ans == INT_MIN ? -1 : ans);
49    }
50};