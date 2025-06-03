class Solution {
public:

    int fun(vector<int>& v, int ind, int time,vector<vector<int>>&dp) {
        if (ind == v.size()) return 0;

        if(dp[ind][time]!=-1){
            return dp[ind][time];
        }

        int pick = v[ind] * (time + 1) + fun(v, ind + 1, time + 1,dp);

        int notPick = fun(v, ind + 1, time,dp);

        return dp[ind][time]=max(pick, notPick);
    }

    int maxSatisfaction(vector<int>& v) {
        int n=v.size();
        sort(v.begin(), v.end()); 
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return fun(v, 0, 0,dp); 
    }
};
