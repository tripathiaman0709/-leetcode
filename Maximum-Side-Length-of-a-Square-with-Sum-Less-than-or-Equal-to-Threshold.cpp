1class Solution {
2public:
3    int maxSideLength(vector<vector<int>>& mat, int k) {
4        int m = mat.size(), n = mat[0].size();
5        vector<vector<int>> pref(m + 1, vector<int>(n + 1, 0));
6
7        for (int i = 1; i <= m; i++) {
8            for (int j = 1; j <= n; j++) {
9                pref[i][j] = mat[i - 1][j - 1]
10                           + pref[i - 1][j]
11                           + pref[i][j - 1]
12                           - pref[i - 1][j - 1];
13            }
14        }
15
16        int low = 0, high = min(m, n), ans = 0;
17
18        while (low <= high) {
19            int mid = (low + high) / 2;
20            bool ok = false;
21
22            for (int i = mid; i <= m && !ok; i++) {
23                for (int j = mid; j <= n; j++) {
24                    int sum = pref[i][j]
25                            - pref[i - mid][j]
26                            - pref[i][j - mid]
27                            + pref[i - mid][j - mid];
28                    if (sum <= k) {
29                        ok = true;
30                        break;
31                    }
32                }
33            }
34
35            if (ok) {
36                ans = mid;
37                low = mid + 1;
38            } else {
39                high = mid - 1;
40            }
41        }
42
43        return ans;
44    }
45};
46