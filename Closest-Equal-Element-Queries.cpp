1class Solution {
2public:
3    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
4        int n = nums.size();
5        unordered_map<int, vector<int>> mp;
6
7        // store indices
8        for (int i = 0; i < n; i++) {
9            mp[nums[i]].push_back(i);
10        }
11
12        vector<int> ans;
13
14        for (int q : queries) {
15            vector<int>& v = mp[nums[q]];
16
17            // only one occurrence
18            if (v.size() == 1) {
19                ans.push_back(-1);
20                continue;
21            }
22
23            int pos = lower_bound(v.begin(), v.end(), q) - v.begin();
24            int res = INT_MAX;
25
26            // left neighbor
27            int left = v[(pos - 1 + v.size()) % v.size()];
28            int d1 = abs(q - left);
29            res = min(res, min(d1, n - d1));
30
31            // right neighbor
32            int right = v[(pos + 1) % v.size()];
33            int d2 = abs(q - right);
34            res = min(res, min(d2, n - d2));
35
36            ans.push_back(res);
37        }
38
39        return ans;
40    }
41};