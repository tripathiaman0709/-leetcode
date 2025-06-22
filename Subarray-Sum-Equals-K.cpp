class Solution {
public:
    int subarraySum(vector<int>& a, int k) {
        int n=a.size();
        unordered_map<int,int>mpp;
        mpp[0]=1;
        vector<int>pre(n);
        int count=0;
        pre[0]=a[0];
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+a[i];
        }
        for(int i=0;i<n;i++){
            int x=pre[i];
            int target=x-k;
            count+=mpp[target];
            mpp[x]++;
        }
        return count;
    }
};