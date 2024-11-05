class Solution {
public:

    int dp[101][101];

    bool fun(int i,int j,string &s1,string &s2,string &s3){
        if(i==s1.size() && j==s2.size() && i+j==s3.size()){
            return true;
        }
        if(i+j>=s3.size()){
            return false;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        bool res=false;

        if(s1[i]==s3[i+j]){
            res= fun(i+1,j,s1,s2,s3);
        }
        if(res==true){
            return dp[i][j]=true;
        }
        if(s2[j]==s3[i+j]){
            res= fun(i,j+1,s1,s2,s3);
        }
        return dp[i][j]=res;
    }

    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.size();
        int m=s2.size();
        int x=s3.size();
        memset(dp,-1,sizeof(dp));
        return fun(0,0,s1,s2,s3);
    }
};