1class Solution {
2    static constexpr int mod = 1000000007;
3
4    long long pow(long long base, int exp) {
5        long long res = 1;
6
7        while (exp) {
8            if (exp & 1)
9                res = res * base % mod;
10
11            base = base * base % mod;
12            exp >>= 1;
13        }
14
15        return res;
16    }
17
18public:
19    int assignEdgeWeights(vector<vector<int>>& edges) {
20        int size = edges.size() + 1;
21        vector<vector<int>> arr(size + 1);
22
23        for (auto& e : edges) {
24            arr[e[0]].push_back(e[1]);
25            arr[e[1]].push_back(e[0]);
26        }
27
28        auto dfs = [&](this auto&& dfs, int node, int prev) -> int {
29            int res = 0;
30
31            for (auto& x : arr[node])
32                if (x != prev)
33                    res = max(res, dfs(x, node) + 1);
34
35            return res;
36        };
37
38        return pow(2, dfs(1, 0) - 1);
39    }
40};