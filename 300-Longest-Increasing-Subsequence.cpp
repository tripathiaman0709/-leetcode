class Solution {
public:
    int dp[2501][2501];

    int fun(int i,int pre,vector<int>&a,int n){
        if(i>=n){
            return 0;
        }

        if(pre!=-1 && dp[i][pre]!=-1){
            return dp[i][pre];
        }
        //take
        //one size increases
        int take=0;
        if(pre==-1 || a[i]>a[pre]){
            take=1+fun(i+1,i,a,n);
        }
        int nottake=fun(i+1,pre,a,n);
        if(pre!=-1){
            return dp[i][pre]= max(take,nottake);
        }
        return max(take,nottake);
    }

    int lengthOfLIS(vector<int>& a) {
        int n=a.size();
        memset(dp,-1,sizeof(dp));
        //LIS
        //simply doing recursion by take and not take then doing memoization
        //and finally tabuation

        return fun(0,-1,a,n);
    }
};