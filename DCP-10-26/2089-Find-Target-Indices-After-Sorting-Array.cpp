class Solution {
public:
    vector<int> targetIndices(vector<int>& v, int k) {
        int n=v.size();
        sort(v.begin(),v.end());
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(v[i]==k){
                ans.push_back(i);
            }
            if(v[i]>k){
                break;
            }
        }

        return ans;
    }
};