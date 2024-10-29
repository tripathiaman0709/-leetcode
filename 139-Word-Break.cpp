class Solution {
public:
    int dp[301];
    bool fun(int i,string s,unordered_set<string>&st){
        int n=s.size();
        if(i>=n){
            return dp[i]=true;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        if(st.count(s)){
            return dp[i]=true;
        }
        for(int l=1;l<=n;l++){
            string s1=s.substr(i,l);

            if(st.count(s1) && fun(i+l,s,st)){
                return dp[i]=true;
            }
        }

        return dp[i]=false;
    }

    bool wordBreak(string s, vector<string>& v) {
        memset(dp,-1,sizeof(dp));
        unordered_set<string>st;
        for(int i=0;i<v.size();i++){
            st.insert(v[i]);
        }        

        return fun(0,s,st);

    }
};