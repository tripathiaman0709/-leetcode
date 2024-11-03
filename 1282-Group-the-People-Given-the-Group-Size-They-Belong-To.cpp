class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& v) {
        int n=v.size();
        map<int,vector<int>>mpp;
        for(int i=0;i<n;i++){
            mpp[v[i]].push_back(i);
        }
        vector<vector<int>>ans;
        for(auto it:mpp){
            vector<int>v1;
            for(auto it1:mpp[it.first]){
                v1.push_back(it1);
                if(v1.size()==it.first){
                ans.push_back(v1);
                v1.clear();
                }
            }
        }
        return ans;
    }
};