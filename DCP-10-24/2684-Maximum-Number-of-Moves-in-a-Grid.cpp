class Solution {
public:

    int dfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>>&dp){
        int n=grid.size();
        int m=grid[0].size();

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int moves=0;
        int delrow[3]={-1,0,1};
        for(int k=0;k<3;k++){
            int newrow=i+delrow[k];
            int newcol=j+1;

            if(newrow<n && newrow>=0 && newcol<m && newcol>=0 && grid[newrow][newcol] > grid[i][j]){
                moves=max(moves,1+dfs(newrow,newcol,grid,dp));
            }
        }            
        return dp[i][j]=moves;
    }

    int maxMoves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        //sare columns me dfs maarke check kr lenge ki kiska sabse bada value aa rha hai
        int maxi=0;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            maxi=max(maxi,dfs(i,0,grid,dp));
        }
        return maxi;
    }
};