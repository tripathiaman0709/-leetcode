class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& a) {
        int n=a.size();
        vector<int>ans(n,-1);
        for(int i=0;i<n;i++){
            int x=a[i];
            for(int j=0;j<x;j++){
                if(((j)|(j+1))==x){
                    ans[i]=j;
                    break;
                }
            }
        }
        return ans;
    }
};