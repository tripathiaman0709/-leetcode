class Solution {
public:
    int dp[101][101];

    // Recursive + memoized coin change (unbounded knapsack)
    int coinChange(int ind, vector<int>& coins, int amount) {
        if (ind >= coins.size()) return 0;
        if (amount == 0) return 1;

        if (dp[ind][amount] != -1) return dp[ind][amount];

        int notTake = coinChange(ind + 1, coins, amount);
        int take = 0;
        if (coins[ind] <= amount)
            take = coinChange(ind, coins, amount - coins[ind]);

        return dp[ind][amount] = take + notTake;
    }

    vector<int> findCoins(vector<int>& numWays) {
        vector<int> coins;
        int n = numWays.size();

        for (int i = 0; i < n; ++i) {
            if (numWays[i] == 1 && coins.empty()) {
                coins.push_back(i + 1);
                continue;
            }

            if (numWays[i] == 0 && coins.empty()) {
                continue;
            }

            if (numWays[i] > 1 && coins.empty()) {
                return {};
            }

            memset(dp, -1, sizeof(dp));
            int total = coinChange(0, coins, i + 1);

            if (total != numWays[i]) {
                coins.push_back(i + 1);

                if (total + 1 != numWays[i]) {
                    return {};
                }
            }
        }

        return coins;
    }
};