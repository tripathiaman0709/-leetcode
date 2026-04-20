1class Solution {
2public:
3    double largestTriangleArea(vector<vector<int>>& points) {
4        int n = points.size();
5        double maxArea = 0.0;
6
7        for (int i = 0; i < n; i++) {
8            for (int j = i + 1; j < n; j++) {
9                for (int k = j + 1; k < n; k++) {
10                    double x1 = points[i][0], y1 = points[i][1];
11                    double x2 = points[j][0], y2 = points[j][1];
12                    double x3 = points[k][0], y3 = points[k][1];
13
14                    double area = abs(
15                        x1*(y2 - y3) +
16                        x2*(y3 - y1) +
17                        x3*(y1 - y2)
18                    ) / 2.0;
19
20                    maxArea = max(maxArea, area);
21                }
22            }
23        }
24
25        return maxArea;
26    }
27};