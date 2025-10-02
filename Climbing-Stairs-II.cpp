class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        costs.insert(costs.begin(), 0); 
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        for(int i=0;i<n;i++){
            if(i+1<=n) dp[i+1] = min(dp[i+1], dp[i] + costs[i+1] + 1);
            if(i+2<=n) dp[i+2] = min(dp[i+2], dp[i] + costs[i+2] + 4);
            if(i+3<=n) dp[i+3] = min(dp[i+3], dp[i] + costs[i+3] + 9);
        }
        return dp[n];
    }
};