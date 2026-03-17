1class Solution {
2public:
3    int largestSubmatrix(vector<vector<int>>& v) {
4        int n = v.size(), m = v[0].size();
5        vector<int> height(m, 0);
6        int ans = 0;
7
8        for(int i = 0; i < n; i++) {
9            // build heights
10            for(int j = 0; j < m; j++) {
11                if(v[i][j] == 1) height[j]++;
12                else height[j] = 0;
13            }
14
15            // sort heights
16            vector<int> temp = height;
17            sort(temp.rbegin(), temp.rend());
18
19            // compute max area
20            for(int j = 0; j < m; j++) {
21                ans = max(ans, temp[j] * (j + 1));
22            }
23        }
24
25        return ans;
26    }
27};