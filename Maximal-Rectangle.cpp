1class Solution {
2public:
3    int largestRectangleArea(vector<int>& heights) {
4        stack<pair<int,int>> st;
5        heights.push_back(0);
6        int maxArea = 0;
7
8        for (int i = 0; i < heights.size(); i++) {
9            int start = i;
10            while (!st.empty() && st.top().second > heights[i]) {
11                auto [idx, h] = st.top();
12                st.pop();
13                maxArea = max(maxArea, h * (i - idx));
14                start = idx;
15            }
16            st.push({start, heights[i]});
17        }
18        heights.pop_back();
19        return maxArea;
20    }
21
22    int maximalRectangle(vector<vector<char>>& matrix) {
23        if (matrix.empty()) return 0;
24
25        int rows = matrix.size(), cols = matrix[0].size();
26        vector<int> heights(cols, 0);
27        int ans = 0;
28
29        for (int i = 0; i < rows; i++) {
30            for (int j = 0; j < cols; j++) {
31                if (matrix[i][j] == '1')
32                    heights[j]++;
33                else
34                    heights[j] = 0;
35            }
36
37            ans = max(ans, largestRectangleArea(heights));
38        }
39
40        return ans;
41    }
42};
43