class Solution {
public:
    vector<int> dfs(int i, vector<int>& nums, unordered_map<int, vector<int>>& dp) {
        if (dp.count(i)) return dp[i];

        vector<int> res = {nums[i]};
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[j] % nums[i] == 0) {
                vector<int> temp = dfs(j, nums, dp);
                if (temp.size() + 1 > res.size()) {
                    res = {nums[i]};
                    res.insert(res.end(), temp.begin(), temp.end());
                }
            }
        }

        return dp[i] = res;
    }

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int, vector<int>> dp;
        vector<int> res;

        for (int i = 0; i < nums.size(); i++) {
            vector<int> temp = dfs(i, nums, dp);
            if (temp.size() > res.size()) res = temp;
        }

        return res;
    }
};
