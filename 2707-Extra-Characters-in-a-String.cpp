class Solution {

    int fun(int i,string &s,unordered_set<string>&st,vector<int>&dp,int n){
        if(i>=n){
            //base case
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }

        //if not pick
        int ans=1+fun(i+1,s,st,dp,n);
        //if pick
        for(int j=i;j<n;j++){
            //creting substrings and checking whether present in hashset or not
            string s1=s.substr(i,j-i+1);
            if(st.count(s1)){
                ans=min(ans,fun(j+1,s,st,dp,n));
            }
        }
        return dp[i]=ans;
    }

public:
    int minExtraChar(string s, vector<string>& dict) {
        int n=s.size();
        vector<int>dp(51,-1);
        //putting elements of dictionary in hashset
        unordered_set<string>st;
        for(int i=0;i<dict.size();i++){
            st.insert(dict[i]);
        }

        //we use recursion + memoization
        //taking the elements or 1+not taking the elements

        int ans=fun(0,s,st,dp,n);
        return ans;
    }
};