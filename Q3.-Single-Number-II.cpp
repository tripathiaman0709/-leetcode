1class Solution {
2public:
3    int singleNumber(vector<int>& nums) {
4        int ones = 0, twos = 0;
5
6        for(int num : nums) {
7            ones = (ones ^ num) & ~twos;
8            twos = (twos ^ num) & ~ones;
9        }
10
11        return ones;
12    }
13};