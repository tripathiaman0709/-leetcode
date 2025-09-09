class Solution {
public:
    int M=1e9+7;
    int solve(int n,int delay,int forget,vector<int>&dp){
        if(n==1){
            return 1;
            //on day 1 only 1 person knew the secret
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int res=0;

        for(int i=n-forget+1;i<=n-delay;i++){
            if(i>0){
                res = (res + solve(i, delay, forget, dp)) % M;
            }
        }
        return dp[n]=res;
    }

    int peopleAwareOfSecret(int n, int delay, int forget) {
        //firstly using simple recursion
        vector<int>dp(n+1,-1);
        int ans=0;
        for(int i=n-forget+1;i<=n;i++){
            if(i>0){
                ans = (ans + solve(i, delay, forget, dp)) % M;
            }
        }
        return ans;
    }
};