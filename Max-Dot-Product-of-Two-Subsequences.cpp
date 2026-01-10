1class Solution {
2public:
3    int dp[501][501];
4
5    int solve(vector<int>& nums1, vector<int>& nums2, int i, int j) {
6        int n = nums1.size(), m = nums2.size();
7
8        if (i == n || j == m)
9            return INT_MIN;
10
11        if (dp[i][j] != -1)
12            return dp[i][j];
13
14        int product = nums1[i] * nums2[j];
15
16        int next = solve(nums1, nums2, i + 1, j + 1);
17        int take = product;
18        if (next != INT_MIN)
19            take = max(take, product + next);
20
21        int skip1 = solve(nums1, nums2, i + 1, j);
22        int skip2 = solve(nums1, nums2, i, j + 1);
23
24        return dp[i][j] = max({take, skip1, skip2});
25    }
26
27    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
28        memset(dp, -1, sizeof(dp));
29        return solve(nums1, nums2, 0, 0);
30    }
31};
32