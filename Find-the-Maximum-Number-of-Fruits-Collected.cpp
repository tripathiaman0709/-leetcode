class Solution {
public:
    //memoization

    int solve1(vector<vector<int>>& v){
        int n=v.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=v[i][i];
        }
        return sum;
    }

    int solve2(int i,int j,vector<vector<int>>& v,vector<vector<int>>& dp){
        //base case
        int n=v.size();

        if(i==j && i==n-1){
            return 0;
        }
        if(i+1>n || j-1<0 || j+1>n){
            return 0;
        }
        if(i>=j){
            return 0;
            //below left diagonal
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int a=v[i][j]+solve2(i+1,j-1,v,dp);
        int b=v[i][j]+solve2(i+1,j,v,dp);
        int c=v[i][j]+solve2(i+1,j+1,v,dp);

        return dp[i][j]=max({a,b,c});
    }

    int solve3(int i,int j,vector<vector<int>>& v,vector<vector<int>>& dp){
        //base case
        int n=v.size();

        if(i==j && i==n-1){
            return 0;
        }
        if(i+1>n || j+1>n || i-1<0){
            return 0;
        }
        if(i<=j){
            return 0;
            //below left diagonal
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int a=v[i][j]+solve3(i-1,j+1,v,dp);
        int b=v[i][j]+solve3(i,j+1,v,dp);
        int c=v[i][j]+solve3(i+1,j+1,v,dp);

        return dp[i][j]=max({a,b,c});
    }


    int maxCollectedFruits(vector<vector<int>>& v) {
        //writing a simple recursion code
        int n=v.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));

        int sum1=solve1(v);
        int sum2=solve2(0,n-1,v,dp);
        int sum3=solve3(n-1,0,v,dp);

        int ans=sum1+sum2+sum3;

        return ans;
    }
};