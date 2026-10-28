class Solution {
public:
    int solve(int i,int j,vector<vector<int>>&grid,int xoro,
              vector<vector<vector<int>>>&dp){

        int n=grid.size();
        int m=grid[0].size();

        if(i>=n || j>=m) return INT_MAX;

        xoro ^= grid[i][j];

        if(i==n-1 && j==m-1){
            return xoro;
        }

        if(dp[i][j][xoro] != -1){
            return dp[i][j][xoro];
        }

        int right = solve(i, j+1, grid, xoro, dp);
        int down  = solve(i+1, j, grid, xoro, dp);

        return dp[i][j][xoro] = min(right, down);
    }

    int minCost(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();

        vector<vector<vector<int>>> dp(n,
            vector<vector<int>>(m, vector<int>(1024, -1)));

        return solve(0,0,grid,0,dp);
    }
};