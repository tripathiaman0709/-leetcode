class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();

        int rr = entrance[0];
        int cc = entrance[1];
        maze[rr][cc] = '+';  // Mark entrance as visited

        queue<pair<int, int>> q;
        q.push({rr, cc});
        int steps = 0;

        int delcol[4] = {1, 0, -1, 0};
        int delrow[4] = {0, 1, 0, -1};

        while (!q.empty()) {
            int qsize = q.size();  // Number of elements in the current BFS level
            for (int i = 0; i < qsize; ++i) {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                // Check if it's an exit
                if ((row != rr || col != cc) && (row == 0 || col == 0 || row == n - 1 || col == m - 1)) {
                    return steps;
                }

                // Explore the neighbors
                for (int i = 0; i < 4; ++i) {
                    int r = delrow[i] + row;
                    int c = delcol[i] + col;

                    if (r >= 0 && r < n && c >= 0 && c < m && maze[r][c] != '+') {
                        q.push({r, c});
                        maze[r][c] = '+';  // Mark cell as visited
                    }
                }
            }
            steps++;  // Increment steps after processing all cells at the current level
        }

        return -1;  // If no exit is found
    }
};
