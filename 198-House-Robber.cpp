class Solution {

    int fun(int i,int n,vector<int>&a,vector<int>&dp){
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1){
            //ie--> already got calculated
            return dp[i];
        }

        //pick
        int pick=a[i]+fun(i+2,n,a,dp);
        //not pick
        int notpick=fun(i+1,n,a,dp);

        return dp[i]=max(pick,notpick);
    }

public:
    int rob(vector<int>& a) {
        //maximum amount our boy could take away 
        //making sure that he cannot rob adjacent houses

        //ofcourse making cases of take and not take
        //memoization

        int n=a.size();
        vector<int>dp(n+1,-1);
        int ans=fun(0,n,a,dp);
        return ans;
    }
};