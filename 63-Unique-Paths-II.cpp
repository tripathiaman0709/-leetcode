class Solution {
public:
    int dp[101][101];
    int fun(int i,int j,vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();

        if(i>n-1 || j>m-1 || grid[i][j]==1){
            //not possoble
            //either out of bound
            //or blocked way
            return 0;
        }
        if(i==n-1 && j==m-1){
            //base case 
            //when reaches end
            return 1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int right=fun(i,j+1,grid);
        int down=fun(i+1,j,grid);

        return dp[i][j]=right+down;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        return fun(0,0,grid);     
    }
};