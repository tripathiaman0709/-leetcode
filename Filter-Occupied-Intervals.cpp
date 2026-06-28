1class Solution {
2public:
3    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
4        sort(occupiedIntervals.begin(), occupiedIntervals.end());
5
6        vector<vector<int>> merged;
7
8        // Merge overlapping/touching intervals
9        for (auto &it : occupiedIntervals) {
10            if (merged.empty() || merged.back()[1] + 1 < it[0]) {
11                merged.push_back(it);
12            } else {
13                merged.back()[1] = max(merged.back()[1], it[1]);
14            }
15        }
16
17        vector<vector<int>> ans;
18
19        // Remove the free interval
20        for (auto &it : merged) {
21            int l = it[0], r = it[1];
22
23            // Completely outside free interval
24            if (r < freeStart || l > freeEnd) {
25                ans.push_back({l, r});
26            }
27            // Left part remains
28            else {
29                if (l < freeStart)
30                    ans.push_back({l, freeStart - 1});
31
32                // Right part remains
33                if (r > freeEnd)
34                    ans.push_back({freeEnd + 1, r});
35            }
36        }
37
38        return ans;
39    }
40};