1class Solution {
2public:
3    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
4        int n = bottomLeft.size(); //topRight.size()
5
6        int maxSide = 0;
7
8        for(int i = 0; i < n; i++) {
9            for(int j = i+1; j < n; j++) {
10                //Width
11                int topRightX   = min(topRight[i][0], topRight[j][0]);
12                int bottomLeftX = max(bottomLeft[i][0], bottomLeft[j][0]);
13
14                int width = topRightX - bottomLeftX;
15
16                //Height
17                int topRightY   = min(topRight[i][1], topRight[j][1]);
18                int bottomLeftY = max(bottomLeft[i][1], bottomLeft[j][1]);
19
20                int height = topRightY - bottomLeftY;
21
22                int side = min(width, height);
23
24                maxSide = max(maxSide, side);
25            }
26        }
27
28        return 1LL * maxSide*maxSide;
29    }
30};