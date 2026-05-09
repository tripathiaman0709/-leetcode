1class Solution {
2public:
3    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
4
5        int n = grid.size();
6        int m = grid[0].size();
7
8        int layers = min(n, m) / 2;
9
10        for (int layer = 0; layer < layers; layer++) {
11
12            int top = layer;
13            int bottom = n - 1 - layer;
14            int left = layer;
15            int right = m - 1 - layer;
16
17            vector<int> v;
18
19            // top row
20            for (int j = left; j <= right; j++)
21                v.push_back(grid[top][j]);
22
23            // right column
24            for (int i = top + 1; i <= bottom; i++)
25                v.push_back(grid[i][right]);
26
27            // bottom row
28            for (int j = right - 1; j >= left; j--)
29                v.push_back(grid[bottom][j]);
30
31            // left column
32            for (int i = bottom - 1; i > top; i--)
33                v.push_back(grid[i][left]);
34
35            int len = v.size();
36            int rot = k % len;
37
38            vector<int> rotated(len);
39
40            // left rotate
41            for (int i = 0; i < len; i++) {
42                rotated[i] = v[(i + rot) % len];
43            }
44
45            int idx = 0;
46
47            // refill top row
48            for (int j = left; j <= right; j++)
49                grid[top][j] = rotated[idx++];
50
51            // refill right column
52            for (int i = top + 1; i <= bottom; i++)
53                grid[i][right] = rotated[idx++];
54
55            // refill bottom row
56            for (int j = right - 1; j >= left; j--)
57                grid[bottom][j] = rotated[idx++];
58
59            // refill left column
60            for (int i = bottom - 1; i > top; i--)
61                grid[i][left] = rotated[idx++];
62        }
63
64        return grid;
65    }
66};