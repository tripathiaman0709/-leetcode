class Solution {
public:
    int maximalSquare(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        //simply using bottom up approach
        //where dp[i][j] signifies the number of square cells that will get formed considering dp[i][j] at bottom right cell
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || j==0){
                    if(grid[i][j]=='1'){
                        dp[i][j]=1;
                    }
                }
                else if(grid[i][j]=='1'){
                    dp[i][j]=1+min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]});
                }

                maxi=max(maxi,dp[i][j]);
            }
        }
        return maxi*maxi;
    }
};