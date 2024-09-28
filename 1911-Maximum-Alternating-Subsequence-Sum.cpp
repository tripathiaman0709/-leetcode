class Solution {
    long long dp[100001][2];
    long long fun(int i,vector<int>&a,int n,int sign){
        if(i==n){
            return 0;
        }
        if(dp[i][sign]!=-1){
            return dp[i][sign];
        }
        //not picking
        long long notpick=fun(i+1,a,n,sign);
        //picking
        if(sign==0){
            a[i]=-a[i];
        }
        long long pick=a[i]+fun(i+1,a,n,!sign);
        

        return dp[i][sign]=max(pick,notpick);
    }


public:
    long long maxAlternatingSum(vector<int>& a) {
        //again a DP question involving take and not take
        int n=a.size();
        memset(dp,-1,sizeof(dp));
        //firstly writing a basic recursion code then memoizing it then doing tabulation
        //and then in the end doing space optimization
        int sign=1;
        return fun(0,a,n,sign);
    }
};