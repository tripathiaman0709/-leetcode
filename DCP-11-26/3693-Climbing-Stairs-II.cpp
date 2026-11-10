
class Solution {
public:
    int climbStairs(int n, vector<int>& v) {
        vector<long long> dp(n + 1, LLONG_MAX);
        dp[0] = 0;

        for (int i = 1; i <= n; i++) {
            if (i >= 1)
                dp[i] = min(dp[i], dp[i-1] + v[i-1] + 1);

            if (i >= 2)
                dp[i] = min(dp[i], dp[i-2] + v[i-1] + 4);

            if (i >= 3)
                dp[i] = min(dp[i], dp[i-3] + v[i-1] + 9);
        }

        return dp[n];
    }
};
