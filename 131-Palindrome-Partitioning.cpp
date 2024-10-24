class Solution {
public:

    void fun(int i,string &s,vector<string>&v,vector<vector<string>>&ans,vector<vector<bool>>&dp){
        if(i==s.size()){
            ans.push_back(v);
            return;
        }
        for(int j=i;j<s.size();j++){
            if(dp[i][j]==true){
                v.push_back(s.substr(i,j-i+1));
                fun(j+1,s,v,ans,dp);
                v.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        int n=s.size();
        vector<vector<bool>>dp(n,vector<bool>(n,false));

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j){
                    dp[i][j]=true;
                }
            }
        }
        for(int l=2;l<=n;l++){
            for(int i=0;i<n-l+1;i++){
                int j=i+l-1;
                if(s[i]==s[j]){
                    if(l==2){
                        dp[i][j]=true;
                    }else{
                        dp[i][j]=(dp[i+1][j-1]);
                    }
                }
            }
        }
        //now dp vector gets filled up completely

        vector<string>v;
        vector<vector<string>>ans;

        fun(0,s,v,ans,dp);
        return ans;
    }
};