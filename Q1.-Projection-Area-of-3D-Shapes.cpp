1class Solution {
2public:
3    int projectionArea(vector<vector<int>>& grid) {
4        int n = grid.size();
5
6        int top = 0;
7        int front = 0;
8        int side = 0;
9
10        for (int i = 0; i < n; i++) {
11            int rowMax = 0;
12            for (int j = 0; j < n; j++) {
13                if (grid[i][j] > 0) top++;
14                rowMax = max(rowMax, grid[i][j]);
15            }
16            front += rowMax;
17        }
18
19        for (int j = 0; j < n; j++) {
20            int colMax = 0;
21            for (int i = 0; i < n; i++) {
22                colMax = max(colMax, grid[i][j]);
23            }
24            side += colMax;
25        }
26
27        return top + front + side;
28    }
29};