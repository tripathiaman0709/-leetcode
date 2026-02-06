1class Solution {
2public:
3    int minRemoval(vector<int>& nums, int k) {
4        sort(nums.begin(), nums.end());
5        int n = nums.size();
6        int i = 0;
7        int maxLen = 0;
8        
9        for (int j = 0; j < n; j++) {
10            while ((long long)nums[j] > (long long)nums[i] * k) {
11                i++;
12            }
13            maxLen = max(maxLen, j - i + 1);
14        }
15        
16        return n - maxLen;
17    }
18};