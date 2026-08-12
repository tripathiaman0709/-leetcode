class Solution {
public:
    int maxSubarrayLength(vector<int>& v, int k) {
        //subarray
        //so simple sliding window problem
        int n=v.size();
        int i=0;
        int j=0;

        int ans=1;

        unordered_map<int,int>mpp;
    
        while(i<n){
            mpp[v[i]]++;
            while(mpp[v[i]]>k){
                mpp[v[j]]--;
                j++;
            }
            int len=i-j+1;

            ans=max(ans,len);
            i++;
        }

        return ans;
    }
};