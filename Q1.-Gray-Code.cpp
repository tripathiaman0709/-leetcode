1class Solution {
2public:
3    vector<int> grayCode(int n) {
4        vector<int> ans = {0};
5
6        for(int i = 0; i < n; i++) {
7            int size = ans.size();
8            for(int j = size - 1; j >= 0; j--) {
9                ans.push_back(ans[j] | (1 << i));
10            }
11        }
12
13        return ans;
14    }
15};