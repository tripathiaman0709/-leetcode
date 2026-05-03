1class Solution {
2public:
3        int maxFixedPoints(vector<int>& A) {
4        vector<int> s;
5        vector<pair<int, int>> B;
6        for (int i = 0; i < A.size(); ++i) {
7            if (i >= A[i]) {
8                B.push_back({i - A[i], A[i]});
9            }
10        }
11        sort(B.begin(), B.end());
12
13        // LIS
14        for (auto& p : B) {
15            int x = p.second;
16            auto it = lower_bound(s.begin(), s.end(), x);
17            if (it == s.end()) {
18                s.push_back(x);
19            } else {
20                *it = x;
21            }
22        }
23        return s.size();
24    }
25};