class Solution {
public:

    int fun(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&dp){
        int n=grid.size();
        int m=grid[0].size();

        if(i==n || j==m){
            return 0;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        if(grid[i][j]==1){
            int right=fun(i,j+1,grid,dp);
            int bottom=fun(i+1,j,grid,dp);
            int diagonal=fun(i+1,j+1,grid,dp);

            return dp[i][j]=1+min({right,bottom,diagonal});
        }

        return 0;
    }

    int countSquares(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        //firstly doing recursion then memoizing it
        //then finally tabulation or bottom up aproach
        int ans=0;

        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)
                ans+=fun(i,j,grid,dp);
            }
        }
        return ans;
    }
};