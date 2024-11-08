class Solution {
public:
    int firstMissingPositive(vector<int>& v) {
        int n=v.size();
        vector<bool>ans(n+1,false);

        for(int i=0;i<n;i++){
            if(v[i]<=n && v[i]>0){
                ans[v[i]]=true;
            }
        }

        for(int i=1;i<=n;i++){
            if(ans[i]==false){
                return i;
            }
        }
        return n+1;
    }
};