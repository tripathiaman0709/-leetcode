class Solution {
public:
    int dp[201][201];
    int fun(int i,int j,vector<vector<int>>& tri){
        int n=tri.size();
        if(i==n-1){
            return dp[i][j]=tri[i][j];
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int down=tri[i][j]+fun(i+1,j,tri);
        int dia =tri[i][j]+fun(i+1,j+1,tri);

        return dp[i][j]=min(down,dia);
    }

    int minimumTotal(vector<vector<int>>& tri) {
        memset(dp,-1,sizeof(dp));
        return fun(0,0,tri);
    }
};