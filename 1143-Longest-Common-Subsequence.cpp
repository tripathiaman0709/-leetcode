class Solution {

/*int dp[1001][1001];

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
}*/

public:
    int longestCommonSubsequence(string s1, string s2) {
        //memset(dp,-1,sizeof(dp));
        int n=s1.size();
        int m=s2.size();
        //doing recursion(2^(m+n)) then memoizing((m+1)*(n+1))
        //now doing tabulation
        //t[i][j]:longest common subsequence between s1 till i and s2 till j

        int v[n+1][m+1];

        //base cases
        for(int i=0;i<=n;i++){
            v[i][0]=0;
        }
        for(int i=0;i<=m;i++){
            v[0][i]=0;
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    v[i][j]=1+v[i-1][j-1];
                }else{
                    v[i][j]=max(v[i-1][j] , v[i][j-1]);
                }
            }
        }
        return v[n][m];
    }
};