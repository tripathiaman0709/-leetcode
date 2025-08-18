class Solution {
public:
    long long perfectPairs(vector<int>& nums) {
        // int n=v.size();
        // int count=0;
        // brute force approach O(n^2)
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         int a=v[i];
        //         int b=v[j];
        //         if(min(abs(a-b),abs(a+b))<=min(abs(a),abs(b)) && max(abs(a-b),abs(a+b))>=max(abs(a),abs(b))){
        //             count++;
        //         }
        //     }
        // }

        // now optimising this approach
        // maybe O(nlogn)

        int n = nums.size();
        vector<long long> absVals(n);
        for (int i = 0; i < n; i++) {
            absVals[i] = llabs(nums[i]);
        }
        
        sort(absVals.begin(), absVals.end());
        long long ans = 0;
        
        for (int i = 0; i < n; i++) {
            long long a = absVals[i];
            long long limit = 2 * a;
            int ub = upper_bound(absVals.begin() + i + 1, absVals.end(), limit) - absVals.begin();
            ans += (ub - (i + 1));
        }
        
        return ans;
    }
};