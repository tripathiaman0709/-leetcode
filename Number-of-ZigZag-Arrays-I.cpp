1class Solution {
2public:
3    static constexpr int MOD = 1000000007;
4
5    int zigZagArrays(int n, int l, int r) {
6        int m = r - l + 1;
7
8        vector<int> dp(m, 1);
9
10        for (int len = 2; len <= n; len++) {
11            reverse(dp.begin(), dp.end());
12
13            long long pref = 0;
14
15            for (int i = 0; i < m; i++) {
16                int old = dp[i];
17
18                dp[i] = pref;
19
20                pref = (pref + old) % MOD;
21            }
22        }
23
24        long long ans = 0;
25
26        for (int x : dp) {
27            ans = (ans + x) % MOD;
28        }
29
30        return (ans * 2) % MOD;
31    }
32};