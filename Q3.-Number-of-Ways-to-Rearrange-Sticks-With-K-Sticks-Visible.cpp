1class Solution {
2public:
3    const int MOD = 1e9 + 7;
4    vector<vector<long long>> memo;
5
6    long long solve(int n, int k) {
7        // base cases
8        if (n == 1) return (k == 1);
9        if (k == 0 || k > n) return 0;
10
11        // memo check
12        if (memo[n][k] != -1) return memo[n][k];
13
14        // recurrence
15        long long visible = solve(n - 1, k - 1);              // n at end
16        long long hidden = (n - 1) * solve(n - 1, k) % MOD;   // n inside
17
18        return memo[n][k] = (visible + hidden) % MOD;
19    }
20
21    int rearrangeSticks(int n, int k) {
22        memo.assign(n + 1, vector<long long>(k + 1, -1));
23        return solve(n, k);
24    }
25};