class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        //to reach the bottom right cell fro the top left cell
        //tabulation method directly

        //dp[i][j] : signifies the minimum distance that needs to be travelled in order to reach i,j from start position
        //returning dp[n][m]

        vector<vector<int>>dp(n+1,vector<int>(m+1,0));

        //base case
        int x=0;
        for(int i=0;i<m;i++){
            x+=grid[0][i];
            dp[0][i]=x;
        }
        int y=0;
        for(int i=0;i<n;i++){
            y+=grid[i][0];
            dp[i][0]=y;
        }

        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                dp[i][j]+= grid[i][j] +min(dp[i-1][j] , dp[i][j-1]);
            }
        }

        return dp[n-1][m-1];
    }
};