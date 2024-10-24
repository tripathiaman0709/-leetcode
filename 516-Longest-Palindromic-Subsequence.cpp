class Solution {
public:

    int longestPalindromeSubseq(string s) {
        //firstly solving by simple recursion
        //using memoization

        //now using the dp on palindrome trick method

        int n = s.size();
        vector<vector<int>>dp(n,vector<int>(n,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j){
                    dp[i][j]=1;
                }
            }
        }
        //i+l-1<n
        //so i<n-l+1
        for(int l=2;l<=n;l++){
            for(int i=0;i<n-l+1;i++){
                int j=i+l-1;

                if(s[i]==s[j]){
                    dp[i][j]=2+dp[i+1][j-1];
                }else{
                    dp[i][j]=max(dp[i][j-1],dp[i+1][j]);
                }
            }
        }

        return dp[0][n-1];
        
    }
};