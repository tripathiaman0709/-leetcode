class Solution {
public:
    int sortPermutation(vector<int>& v) {
        int n=v.size();
        int ans=-1;
        for(int i=0;i<n;i++){
            if(v[i]!=i){
                ans=ans&v[i];
            }
        }
        if(ans==-1){
            return 0;
        }
        return ans;
    }
};