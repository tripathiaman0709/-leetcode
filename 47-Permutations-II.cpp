class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& v) {
        sort(v.begin(),v.end());
        vector<vector<int>>sol;
        
        do {
            vector<int>a;
            for (auto it:v){
                a.push_back(it);
            }
            sol.push_back(a);
        } while (next_permutation(v.begin(), v.end()));
        return sol;
    }
};