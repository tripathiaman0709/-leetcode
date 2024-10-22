class Solution {
public:
    int dp[501][501];

    int fun(string s1,string s2,int i,int j){
        if(i==0){
            return j;
        }
        if(j==0){
            return i;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        if(s1[i-1]==s2[j-1]){
            return dp[i][j]=fun(s1,s2,i-1,j-1);
        }else{
            int ins=1+fun(s1,s2,i,j-1);
            int del=1+fun(s1,s2,i-1,j);
            int rep=1+fun(s1,s2,i-1,j-1);

            return dp[i][j]=min({ins,del,rep});
        }
        return 0;
    }

    int minDistance(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();

        memset(dp,-1,sizeof(dp));

        return fun(s1,s2,n,m);
    }
};