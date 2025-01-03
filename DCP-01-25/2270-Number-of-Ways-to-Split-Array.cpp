class Solution {
public:
    int waysToSplitArray(vector<int>& v) {
        int n=v.size();
        vector<long long>pre(n,0);
        pre[0]=v[0];
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+v[i];
        }
        long long sum=0;
        for(int i=0;i<n;i++){
            sum+=v[i];
        }
        int ans=0;
        for(int i=0;i<n-1;i++){
            long long x=pre[i];
            long long y=sum-pre[i];
            if(x>=y){
                ans++;
            }
        }
        return ans;
    }
};