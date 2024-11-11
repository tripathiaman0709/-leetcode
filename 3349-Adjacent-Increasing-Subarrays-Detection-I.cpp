class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& v, int k) {
        int n=v.size();
        vector<int>pre(n,1);
        for(int i=1;i<n;i++){
            if(v[i]>v[i-1]){
                pre[i]+=pre[i-1];
            }
        }
        for(int i=0;i<n-k;i++){
            if(pre[i]>=k && pre[i+k]>=k){
                return true;
            }
        }
        return false;
    }
};