class Solution {
public:
    int maxSatisfaction(vector<int>& v) {
        int n = v.size();
        sort(v.begin(), v.end());

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int ind = n - 1; ind >= 0; ind--) {
            for (int time = ind; time >= 0; time--) {
                int pick = v[ind] * (time + 1) + dp[ind + 1][time + 1];
                int notPick = dp[ind + 1][time];
                dp[ind][time] = max(pick, notPick);
            }
        }

        return dp[0][0];
    }
};
