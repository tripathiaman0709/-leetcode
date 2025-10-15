class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& v) {
    int n=v.size();
    vector<int>pre(n,1);
    vector<int>suff(n,1);
    for(int i=1;i<n;i++){
        if(v[i]>v[i-1]){
            pre[i]+=pre[i-1];
        }
    }
    for(int i=n-2;i>=0;i--){
        if(v[i]<v[i+1]){
            suff[i]+=suff[i+1];
        }
    }
    int ans=0;
    for(int i=0;i<n-1;i++){
        ans=max(ans,min(pre[i],suff[i+1]));
    }
    return ans;  
    }
};