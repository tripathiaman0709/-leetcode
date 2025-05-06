class Solution {
public:
    vector<int> buildArray(vector<int>& v) {
        int n=v.size();
        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
            ans[i]=v[v[i]];
        }
        return ans;
    }
};