1class Solution {
2public:
3    int solve(int i,int j,vector<vector<int>>&grid,int xoro,
4              vector<vector<vector<int>>>&dp){
5
6        int n=grid.size();
7        int m=grid[0].size();
8
9        if(i>=n || j>=m) return INT_MAX;
10
11        xoro ^= grid[i][j];
12
13        if(i==n-1 && j==m-1){
14            return xoro;
15        }
16
17        if(dp[i][j][xoro] != -1){
18            return dp[i][j][xoro];
19        }
20
21        int right = solve(i, j+1, grid, xoro, dp);
22        int down  = solve(i+1, j, grid, xoro, dp);
23
24        return dp[i][j][xoro] = min(right, down);
25    }
26
27    int minCost(vector<vector<int>>& grid) {
28        int n=grid.size(), m=grid[0].size();
29
30        vector<vector<vector<int>>> dp(n,
31            vector<vector<int>>(m, vector<int>(1024, -1)));
32
33        return solve(0,0,grid,0,dp);
34    }
35};