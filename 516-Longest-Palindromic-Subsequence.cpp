class Solution {
public:

    int dp[1001][1001];

    int fun(int i,int j,string &s){
        if(i>j){
            return 0;
        }
        if(i==j){
            return 1;
        }
        else{
            if(dp[i][j]!=-1){
                return dp[i][j];
            }

            if(s[i]==s[j]){
                return dp[i][j]= 2+fun(i+1,j-1,s);
            }else{
                return dp[i][j]= max(fun(i+1,j,s),fun(i,j-1,s));
            }
        }
    }

    int longestPalindromeSubseq(string s) {
        //firstly solving by simple recursion
        //using memoization

        memset(dp,-1,sizeof(dp));
        int n = s.size();
        return fun(0,n-1,s);
    }
};