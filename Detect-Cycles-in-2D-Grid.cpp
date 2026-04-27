1class Solution {
2public:
3    bool dfs(int i, int j, int pi, int pj,
4             vector<vector<char>>& grid,
5             vector<vector<int>>& vis) {
6        
7        int n = grid.size(), m = grid[0].size();
8        vis[i][j] = 1;
9
10        int dr[4] = {-1, 0, 1, 0};
11        int dc[4] = {0, -1, 0, 1};
12
13        for (int d = 0; d < 4; d++) {
14            int ni = i + dr[d];
15            int nj = j + dc[d];
16
17            if (ni < 0 || nj < 0 || ni >= n || nj >= m)
18                continue;
19
20            if (grid[ni][nj] != grid[i][j])
21                continue;
22
23            if (!vis[ni][nj]) {
24                if (dfs(ni, nj, i, j, grid, vis))
25                    return true;
26            } 
27            else if (ni != pi || nj != pj) {
28                return true;
29            }
30        }
31
32        return false;
33    }
34
35    bool containsCycle(vector<vector<char>>& grid) {
36        int n = grid.size(), m = grid[0].size();
37        vector<vector<int>> vis(n, vector<int>(m, 0));
38
39        for (int i = 0; i < n; i++) {
40            for (int j = 0; j < m; j++) {
41                if (!vis[i][j]) {
42                    if (dfs(i, j, -1, -1, grid, vis))
43                        return true;
44                }
45            }
46        }
47
48        return false;
49    }
50};