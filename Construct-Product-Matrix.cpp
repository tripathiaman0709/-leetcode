1class Solution {
2public:
3    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
4        int n = grid.size();
5        int m = grid[0].size();
6
7        vector<int> v;
8        for(int i = 0; i < n; i++) {
9            for(int j = 0; j < m; j++) {
10                v.push_back(grid[i][j] % 12345); // optional optimization
11            }
12        }
13
14        int sz = v.size();
15        vector<int> pre(sz, 1), suff(sz, 1);
16
17        // prefix
18        for(int i = 1; i < sz; i++) {
19            pre[i] = (1LL * pre[i-1] * v[i-1]) % 12345;
20        }
21
22        // suffix
23        for(int i = sz-2; i >= 0; i--) {
24            suff[i] = (1LL * suff[i+1] * v[i+1]) % 12345;
25        }
26
27        // reconstruct
28        int count = 0;
29        for(int i = 0; i < n; i++) {
30            for(int j = 0; j < m; j++) {
31                grid[i][j] = (1LL * pre[count] * suff[count]) % 12345;
32                count++;
33            }
34        }
35
36        return grid;
37    }
38};