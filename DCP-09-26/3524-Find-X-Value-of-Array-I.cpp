class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k), state(k);
        for (int x : nums) {
            int rem = x % k;
            vector<long long> next(k);
            for (int r = 0; r < k; r++) {
                int productRem = (r * rem) % k;
                next[productRem] += state[r];
                ans[productRem] += state[r];
            }
            next[rem]++;
            ans[rem]++;
            state = next;
        }
        return ans;
    }
};