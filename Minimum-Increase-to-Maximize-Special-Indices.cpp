1class Solution {
2public:
3    long long r(vector<int> &nums, int pos, bool skip, vector<vector<long long>> &dp) {
4        int n = nums.size();
5        if (pos >= n - 1) return 0;
6        if (dp[skip][pos] != -1) return dp[skip][pos];
7
8        long long ans = max(0, max(nums[pos - 1], nums[pos + 1]) + 1 - nums[pos]);
9        
10        if (skip) 
11            return dp[skip][pos] = ans + r(nums, pos + 2, skip, dp);
12
13        dp[true][pos]  = ans + r(nums, pos + 3, true, dp);
14        dp[false][pos] = ans + r(nums, pos + 2, false, dp);
15
16        return min(dp[0][pos], dp[1][pos]);
17    }
18    
19    long long minIncrease(vector<int>& nums) {
20        int n = nums.size();
21        
22        // Odd length: fixed pattern
23        if (n % 2) {
24            long long ans = 0;
25            for (int i = 1; i < n - 1; i += 2) {
26                ans += max(0, max(nums[i-1], nums[i+1]) + 1 - nums[i]);
27            }
28            return ans;                    
29        }
30        
31        // Even length: DP with skip
32        vector<vector<long long>> dp(2, vector<long long>(n, -1));
33        
34        return min(r(nums, 1, false, dp), r(nums, 2, true, dp));
35    }
36};