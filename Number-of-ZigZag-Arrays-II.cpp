1class Solution {
2public:
3    static const long long MOD = 1000000007LL;
4
5    vector<vector<long long>> multiply(
6        const vector<vector<long long>>& A,
7        const vector<vector<long long>>& B
8    ) {
9        int sz = A.size();
10
11        vector<vector<long long>> C(sz, vector<long long>(sz, 0));
12
13        for (int i = 0; i < sz; i++) {
14            for (int k = 0; k < sz; k++) {
15                if (A[i][k] == 0) continue;
16
17                long long cur = A[i][k];
18
19                for (int j = 0; j < sz; j++) {
20                    if (B[k][j] == 0) continue;
21
22                    C[i][j] = (C[i][j] + cur * B[k][j]) % MOD;
23                }
24            }
25        }
26
27        return C;
28    }
29
30    int zigZagArrays(int n, int l, int r) {
31        int m = r - l + 1;
32        int sz = 2 * m;
33
34        vector<vector<long long>> T(sz, vector<long long>(sz, 0));
35
36        for (int x = 0; x < m; x++) {
37
38            for (int y = x + 1; y < m; y++) {
39                T[x][m + y] = 1;
40            }
41
42            for (int y = 0; y < x; y++) {
43                T[m + x][y] = 1;
44            }
45        }
46
47        vector<vector<long long>> result(sz, vector<long long>(sz, 0));
48        for (int i = 0; i < sz; i++) {
49            result[i][i] = 1;
50        }
51
52        long long power = n - 1;
53
54        while (power > 0) {
55            if (power & 1) {
56                result = multiply(result, T);
57            }
58
59            T = multiply(T, T);
60            power >>= 1;
61        }
62
63        vector<long long> initial(sz, 1);
64
65        long long answer = 0;
66
67        for (int i = 0; i < sz; i++) {
68            long long rowSum = 0;
69
70            for (int j = 0; j < sz; j++) {
71                rowSum = (rowSum + result[i][j]) % MOD;
72            }
73
74            answer = (answer + rowSum) % MOD;
75        }
76
77        return (int)answer;
78    }
79};