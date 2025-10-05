class Solution {
public:
    int n, m;
    vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
    
    void dfs(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& ocean) {
        ocean[r][c] = 1;
        for (auto &d : dirs) {
            int nr = r + d[0], nc = c + d[1];
            if (nr>=0 && nr<n && nc>=0 && nc<m && !ocean[nr][nc] && grid[nr][nc] >= grid[r][c]) {
                dfs(nr, nc, grid, ocean);
            }
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& grid) {
        n = grid.size(); 
        m = grid[0].size();
        
        vector<vector<int>> pac(n, vector<int>(m, 0)), atl(n, vector<int>(m, 0));
        
        for (int i = 0; i < n; i++) {
            dfs(i, 0, grid, pac);
            dfs(i, m-1, grid, atl);
        }
        for (int j = 0; j < m; j++) {
            dfs(0, j, grid, pac);
            dfs(n-1, j, grid, atl);
        }
        
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (pac[i][j] && atl[i][j]) ans.push_back({i, j});
            }
        }
        return ans;
    }
};
