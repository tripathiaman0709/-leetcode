class Solution {
public:
    int maximumCandies(vector<int>& v, long long k) {
        long long sum = accumulate(v.begin(), v.end(), 0LL);
        if (sum < k) return 0;
        
        int l = 1, r = *max_element(v.begin(), v.end()), ans = 0;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            long long cnt = 0;
            for (int c : v) cnt += (c / mid);
            
            if (cnt >= k) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};
