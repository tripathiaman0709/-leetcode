class Solution {
public:
    int dp[501][501];

    int fun(string s1,string s2,int i,int j){
        if(i==s1.size()){
            return s2.size()-j;
        }
        if(j==s2.size()){
            return s1.size()-i;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        if(s1[i]==s2[j]){
            return dp[i][j]=fun(s1,s2,i+1,j+1);
        }else{
            int ins=1+fun(s1,s2,i,j+1);
            int del=1+fun(s1,s2,i+1,j);
            int rep=1+fun(s1,s2,i+1,j+1);

            return dp[i][j]=min({ins,del,rep});
        }
        return 0;
    }

    int minDistance(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();

        memset(dp,-1,sizeof(dp));

        return fun(s1,s2,0,0);
    }
};