class Solution {

int dp[1001][1001];

int fun(int i,int j,string &s1,string &s2,int n,int m){
    if(i>=n || j>=m){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(s1[i]==s2[j]){
        return dp[i][j]=1+fun(i+1,j+1,s1,s2,n,m);
    }else{
        return dp[i][j]=max(fun(i+1,j,s1,s2,n,m),fun(i,j+1,s1,s2,n,m));
    }
}

public:
    int longestCommonSubsequence(string s1, string s2) {
        memset(dp,-1,sizeof(dp));
        int n=s1.size();
        int m=s2.size();
        //doing recursion then memoizing
        return fun(0,0,s1,s2,n,m);
    }
};