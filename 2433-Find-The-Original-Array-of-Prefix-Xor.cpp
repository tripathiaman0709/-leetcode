class Solution {
public:
    vector<int> findArray(vector<int>& v) {
        int n=v.size();
        vector<int>ans;
        ans.push_back(v[0]);
        for(int i=0;i<n-1;i++){
            ans.push_back(v[i]^v[i+1]);
        }      
        return ans;
    }
};