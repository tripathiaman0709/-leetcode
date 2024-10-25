class Solution {
public:
    int minCut(string s) {
        int n=s.size();
        vector<vector<bool>>dp(n,vector<bool>(n,false));

        for(int i=0;i<n;i++){
            dp[i][i]=true;
        }
        for(int l=2;l<=n;l++){
            for(int i=0;i<n-l+1;i++){
                int j=i+l-1;
                if(s[i]==s[j]){
                    if(l==2){
                        dp[i][j]=true;
                    }else if(dp[i+1][j-1]==true){
                        dp[i][j]=true;
                    }
                }
            }
        }
        //now we have filled the palindrome vector

        vector<int>v(n,0);
        for(int i=0;i<n;i++){
            if(dp[0][i]==true){
                v[i]=0;
            }else{
                v[i]=INT_MAX;
                for(int k=0;k<i;k++){
                    if(dp[k+1][i]==true && 1+v[k]<v[i]){
                        v[i]=1+v[k];
                    }
                }
            }
        }

        return v[n-1];
    }
};