1class Solution {
2public:
3    int maxBuilding(int n, vector<vector<int>>& restrictions) {
4        restrictions.push_back({1, 0});
5        
6        restrictions.push_back({n, n - 1});
7
8        sort(restrictions.begin(), restrictions.end());
9
10        int m = restrictions.size();
11
12        for (int i = 1; i < m; i++) {
13            int dist = restrictions[i][0] - restrictions[i - 1][0];
14
15            restrictions[i][1] = min(
16                restrictions[i][1],
17                restrictions[i - 1][1] + dist
18            );
19        }
20
21        for (int i = m - 2; i >= 0; i--) {
22            int dist = restrictions[i + 1][0] - restrictions[i][0];
23
24            restrictions[i][1] = min(
25                restrictions[i][1],
26                restrictions[i + 1][1] + dist
27            );
28        }
29
30        long long ans = 0;
31
32        for (int i = 1; i < m; i++) {
33            long long x1 = restrictions[i - 1][0];
34            long long h1 = restrictions[i - 1][1];
35
36            long long x2 = restrictions[i][0];
37            long long h2 = restrictions[i][1];
38
39            long long dist = x2 - x1;
40
41            long long peak =
42                max(h1, h2) +
43                (dist - llabs(h1 - h2)) / 2;
44
45            ans = max(ans, peak);
46        }
47
48        return (int)ans;
49    }
50};