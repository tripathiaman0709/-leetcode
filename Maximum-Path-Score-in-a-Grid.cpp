class Solution {
public:

    int solve(int i, int j, vector<vector<int>>& grid, int k,vector<vector<vector<int>>>&dp) {
        int n = grid.size();
        int m = grid[0].size();

        if (i >= n || j >= m || k < 0) return INT_MIN;

        int cost = (grid[i][j] == 2 ? 1 : grid[i][j]);

        if (k < cost) return INT_MIN;

        if (i == n - 1 && j == m - 1) {
            return grid[i][j];
        }

        if(dp[i][j][k]!=-1){
            return dp[i][j][k];
        }

        int remainingK = k - cost;

        int down = solve(i + 1, j, grid, remainingK,dp);
        int right = solve(i, j + 1, grid, remainingK,dp);

        int bestChild = max(down, right);
        if (bestChild == INT_MIN) {
            return dp[i][j][k] = INT_MIN;
        }
        return dp[i][j][k]=grid[i][j] + bestChild;
    }

    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(m+1,vector<int>(k+1,-1)));
        int ans= solve(0, 0, grid, k,dp);
        if(ans==INT_MIN){
            return -1;
        }
        return ans;
    }
};
