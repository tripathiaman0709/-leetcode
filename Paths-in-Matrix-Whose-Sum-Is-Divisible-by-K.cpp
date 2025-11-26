1class Solution {
2public:
3
4    int solve(int i, int j, int rem, vector<vector<int>>& grid, int k,
5          vector<vector<vector<int>>>& dp) {
6            int n = grid.size(), m = grid[0].size();
7            if (i == n || j == m) return 0;
8
9            rem = (rem + grid[i][j]) % k;
10
11            if (i == n-1 && j == m-1)
12                return rem == 0;
13
14            int &ans = dp[i][j][rem];
15            if (ans != -1) return ans;
16
17            long long right = solve(i, j+1, rem, grid, k, dp);
18            long long down  = solve(i+1, j, rem, grid, k, dp);
19            ans = (right + down) % 1000000007;
20            return ans;
21    }
22
23
24    int numberOfPaths(vector<vector<int>>& grid, int k) {
25        int n=grid.size();
26        int m=grid[0].size();
27
28        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(m+1,vector<int>(k,-1)));
29
30        int ans=solve(0,0,0,grid,k,dp);
31
32        return ans;
33    }
34};