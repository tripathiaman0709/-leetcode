1class Solution {
2public:
3    typedef long long ll;
4    ll total = 0;
5
6    bool checkHorCuts(vector<vector<int>>& grid) {
7        int m = grid.size();
8        int n = grid[0].size();
9
10        unordered_set<ll> st;
11        ll top = 0;
12
13        for(int i = 0; i <= m-2; i++) {
14
15            for(int j = 0; j < n; j++) {
16                st.insert(grid[i][j]);
17                top += grid[i][j];
18            }
19
20            ll bottom = (total - top);
21            ll diff = top - bottom;
22
23            if (diff == 0) return true;
24
25            if (diff == (ll)grid[0][0])   return true;
26            if (diff == (ll)grid[0][n-1]) return true;
27            if (diff == (ll)grid[i][0]) return true;
28
29            if(i > 0 && n > 1 && st.count(diff)) {
30                return true;
31            }
32        }
33
34        return false;
35    }
36
37    bool canPartitionGrid(vector<vector<int>>& grid) {
38        int m = grid.size();
39        int n = grid[0].size();
40
41        for(int i = 0; i < m; i++) {
42            for(int j = 0; j < n; j++) {
43                total += grid[i][j];
44            }
45        }
46
47        //Horizontal cuts
48        if(checkHorCuts(grid)) {
49            return true;
50        }
51
52        reverse(begin(grid), end(grid));
53
54        if(checkHorCuts(grid)) {
55            return true;
56        }
57
58        reverse(begin(grid), end(grid)); //original grid  m*n
59
60        //Vertical cuts checking but by using checkHorCuts method
61        //Transpose of grid and then do checkHorCuts
62        vector<vector<int>> transposeGrid(n, vector<int>(m)); //n*m
63
64        for(int i = 0; i < m; i++) {
65            for(int j = 0; j < n; j++) {
66                transposeGrid[j][i] = grid[i][j];
67            }
68        }
69
70        if(checkHorCuts(transposeGrid)) {
71            return true;
72        }
73
74        reverse(begin(transposeGrid), end(transposeGrid));
75
76        if(checkHorCuts(transposeGrid)) {
77            return true;
78        }
79
80        return false;
81
82    }
83};