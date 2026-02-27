1class Solution {
2public:
3    int n;
4    vector<int> nums;
5    vector<int> colors;
6    vector<long long> memo;
7
8    long long dfs(int i = 0) {
9        if (i == n)  // All houses checked
10            return 0;
11
12        if (memo[i] != -1) 
13            return memo[i];
14
15        bool canrob_both = (i + 1 == n || colors[i] != colors[i + 1]);
16        if (canrob_both)  // If we can rob both houses, we do it
17            return memo[i] = nums[i] + dfs(i + 1);
18
19        // If we have to choose, we try both options
20        return memo[i] = max(nums[i] + dfs(i + 2), dfs(i + 1));
21    }
22
23    long long rob(vector<int>& nums, vector<int>& colors) {
24        this->nums = nums;
25        this->colors = colors;
26        this->n = nums.size();
27        memo.assign(nums.size(), -1);
28        return dfs();
29    }
30};