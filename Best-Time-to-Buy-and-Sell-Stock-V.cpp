1class Solution {
2public:
3    int n, K;
4    vector<int> prices;
5    long long dp[1005][505][3];
6
7    long long dfs(int i, int t, int state) {
8        if (i == n) {
9            return (state == 0 ? 0 : LLONG_MIN / 2);
10        }
11
12        if (dp[i][t][state] != -1)
13            return dp[i][t][state];
14
15        long long ans = dfs(i + 1, t, state);
16
17        if (state == 0) {
18            ans = max(ans, dfs(i + 1, t, 1) - prices[i]);
19            ans = max(ans, dfs(i + 1, t, 2) + prices[i]);
20        }
21        else if (state == 1 && t < K) {
22            ans = max(ans, dfs(i + 1, t + 1, 0) + prices[i]);
23        }
24        else if (state == 2 && t < K) {
25            ans = max(ans, dfs(i + 1, t + 1, 0) - prices[i]);
26        }
27
28        return dp[i][t][state] = ans;
29    }
30
31    long long maximumProfit(vector<int>& prices, int k) {
32        this->prices = prices;
33        n = prices.size();
34        K = k;
35
36        memset(dp, -1, sizeof(dp));
37        return dfs(0, 0, 0);
38    }
39};