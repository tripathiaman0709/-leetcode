class Solution {
    int dp[2501][2501];
    int fun(int i,int pre,vector<vector<int>>&a,int n){
        if(i==n){
            return 0;
        }
        //pick
        if(pre!=-1 && dp[i][pre]!=-1){
            return dp[i][pre];
        }
        int pick=0;
        if(pre==-1 || a[i][0]>a[pre][1]){
            pick=1+fun(i+1,i,a,n);
        }
        //not pick
        int notpick=fun(i+1,pre,a,n);
        if(pre!=-1){
            return dp[i][pre]=max(pick,notpick);
        }
        return max(pick,notpick);
    }


public:
    int findLongestChain(vector<vector<int>>& a) {
        int n=a.size();
        memset(dp,-1,sizeof(dp));
        sort(a.begin(),a.end());
        //recursion pick and not pick
        //to form the longest lengthed chain possible

        return fun(0,-1,a,n);

    }
};