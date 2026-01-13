1class Solution {
2public:
3    bool check(long double y, vector<vector<int>>& squares, long double totalArea) {
4
5        long double part2 = 0;
6
7        for (auto &i : squares) {
8
9            double Y = i[1];
10            long double side =i[2];
11
12            if (Y >= y) {
13
14            } else {
15                double finalY = Y + i[2];
16
17                if (finalY <= y) {
18                    part2 += side*side;
19                } else {
20
21                    part2 += (y - Y) *side;
22                }
23            }
24        }
25
26        return part2 < totalArea / 2;
27    }
28    double separateSquares(vector<vector<int>>& squares) {
29
30       long double low = 0;
31       long double high = 0;
32
33        double ans = 1e9;
34
35        long double totalArea = 0;
36        for (auto &i : squares) {
37            double y = i[1];
38           long double side = i[2];
39            totalArea += side*side;
40            high = max(high, y + side);
41        }
42
43        int count = 0;
44
45        while (high - low >= 1e-6 && count < 60) {
46            long double mid = (low + high) / 2;
47            count++;
48            if (check(mid, squares, totalArea)) {
49                low = mid;
50
51                ans = mid;
52            } else {
53                high = mid;
54            }
55        }
56
57        return low;
58    }
59};