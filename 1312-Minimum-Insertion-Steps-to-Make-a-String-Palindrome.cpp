class Solution {
public:
    int minInsertions(string s) {
        //bigger question is that when s[i]!=s[j]
        //will you do insertion on left side or the right side

        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,0));

        for(int l=2;l<=n;l++){
            for(int i=0;i<n-l+1;i++){
                int j=i+l-1;
                if(s[i]==s[j]){
                    dp[i][j]=dp[i+1][j-1];
                }else{
                    dp[i][j]=1+min(dp[i+1][j],dp[i][j-1]);
                }
            }
        }

        return dp[0][n-1];
    }
};