class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        int desc=1;
        int inc=1;
        int minc=1;
        int mdesc=1;

        for(int i=0;i<n-1;i++){
            if(nums[i+1]>nums[i])
            inc++;
            else
            inc=1;
            minc=max(minc,inc);
        }
        for(int i=0;i<n-1;i++){
            if(nums[i+1]<nums[i])
            desc++;
            else
            desc=1;
            mdesc=max(mdesc,desc);
        }
        int ans=max(minc,mdesc);
        return ans;
    }
};