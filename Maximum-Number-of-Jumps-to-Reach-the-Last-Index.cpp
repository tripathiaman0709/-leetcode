1class Solution {
2public:
3    int maximumJumps(vector<int>& v, int k) {
4
5        int n = v.size();
6
7        vector<int> dp(n, -1);
8
9        dp[0] = 0;
10
11        for (int i = 1; i < n; i++) {
12
13            for (int j = 0; j < i; j++) {
14
15                if (abs(v[i] - v[j]) <= k && dp[j] != -1) {
16
17                    dp[i] = max(dp[i], dp[j] + 1);
18                }
19            }
20        }
21
22        return dp[n - 1];
23    }
24};