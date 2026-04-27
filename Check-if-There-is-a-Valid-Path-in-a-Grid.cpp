1class Solution {
2public:
3    int m, n;
4
5    unordered_map<int, vector<vector<int>>> directions = {
6        {1, {{0, -1}, {0, 1}}},
7        {2, {{-1, 0}, {1, 0}}},
8        {3, {{0, -1}, {1, 0}}},
9        {4, {{0, 1}, {1, 0}}},
10        {5, {{0, -1}, {-1, 0}}},
11        {6, {{-1, 0}, {0, 1}}}
12    };
13
14    bool dfs(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& visited) {
15        if(i == m-1 && j == n-1)
16            return true;
17        
18        visited[i][j] = true;
19
20        for(auto &dir : directions[grid[i][j]]) {
21            int new_i = i + dir[0];
22            int new_j = j + dir[1];
23
24            if(new_i < 0 || new_i >= m || new_j < 0 || new_j >= n || visited[new_i][new_j])
25                continue;
26            
27            //IMPORTANT = can you come back to i and j from new_i and new_j
28            for(auto &backDir : directions[grid[new_i][new_j]]) {
29                if(new_i + backDir[0] == i &&
30                   new_j + backDir[1] == j) {
31                        if(dfs(grid, new_i, new_j, visited)) {
32                            return true;
33                        }
34                   }
35            }
36        }
37
38        return false;
39    }
40
41    bool hasValidPath(vector<vector<int>>& grid) {
42        m = grid.size();
43        n = grid[0].size();
44
45        vector<vector<bool>> visited(m, vector<bool>(n, false));
46        //T.C : O(m*n)
47
48        return dfs(grid, 0, 0, visited);
49    }
50};