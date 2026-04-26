1class Solution {
2public:
3    long long minOperations(vector<int>& nums) {
4        long long ans = 0;
5        int n = nums.size();
6
7        for(int i = 0; i < n - 1; i++){
8            if(nums[i] > nums[i+1]){
9                ans += (nums[i] - nums[i+1]);
10            }
11        }
12
13        return ans;
14    }
15};