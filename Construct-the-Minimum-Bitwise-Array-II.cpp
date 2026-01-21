1class Solution {
2public:
3    vector<int> minBitwiseArray(vector<int>& nums) {
4        vector<int> ans;
5        ans.reserve(nums.size());
6        
7        for (int n : nums) {
8            if (n % 2 == 0) {
9                ans.push_back(-1);
10            } else {
11                int t = n + 1;
12                int lowbit = t & -t;
13                ans.push_back(n - (lowbit >> 1));
14            }
15        }
16        return ans;
17    }
18};