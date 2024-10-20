class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();

        //filling up the 2d table using bottom up approch
        vector<vector<int>>dp(n+1,vector<int>(m+1));
        //base case is dp vector with either row or column equal to zero is zero

        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0 || j==0){
                    dp[i][j]=i+j;
                }else if(s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                    dp[i][j]=1+min(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        //now time to print the string
        string ans="";
        int i=n;
        int j=m;
        while(i>0 && j>0){
           if(s1[i-1]==s2[j-1]){
                    ans.push_back(s1[i-1]);
                    i--;
                    j--;
            }else{
                if(dp[i-1][j]>dp[i][j-1]){
                    ans.push_back(s2[j-1]);
                    j--;
                }else{
                    ans.push_back(s1[i-1]);
                    i--;
                }
            }
        }
        while(i>0){
            ans.push_back(s1[i-1]);
            i--;
        }
        while(j>0){
            ans.push_back(s2[j-1]);
            j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};