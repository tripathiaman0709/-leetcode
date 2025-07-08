class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        // Group rides by end time
        unordered_map<int, vector<vector<int>>> rideMap;
        for (auto& ride : rides) {
            int start = ride[0], end = ride[1], tip = ride[2];
            rideMap[end].push_back({start, tip});
        }

        vector<long long> dp(n + 1, 0); // dp[i] = max earnings till point i

        for (int i = 1; i <= n; ++i) {
            // By default, carry forward the previous earnings
            dp[i] = dp[i - 1];

            // If there are rides ending at point i
            for (auto& ride : rideMap[i]) {
                int start = ride[0], tip = ride[1];
                long long profit = (i - start + tip) + dp[start];
                dp[i] = max(dp[i], profit);
            }
        }

        return dp[n];
    }
};
