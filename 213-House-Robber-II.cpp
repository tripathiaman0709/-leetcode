class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        if(nums.size() == 1)
            return nums[0];
        // there are 2 ways to rob 
        int dp[nums.size()];
        
        // 1. rob the first house => u can't rob the last one
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for(int i=2 ; i<nums.size()-1 ; i++)
            dp[i] = max( nums[i]+ dp[i-2], dp[i-1] );
        int amt1 = dp[nums.size()-2];
        
        // 2. rob the second house till the last one
        dp[0] = 0;
        dp[1] = nums[1];
        for(int i=2 ; i<nums.size() ; i++)
            dp[i] = max( nums[i]+ dp[i-2], dp[i-1] );
        
        return max(amt1, dp[nums.size()-1]);
    }
};