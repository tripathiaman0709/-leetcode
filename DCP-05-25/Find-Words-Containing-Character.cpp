class Solution {
public:
    vector<int> findWordsContaining(vector<string>& v, char x) {
        int n=v.size();
        vector<int>ans;
        for (int i = 0; i < v.size(); ++i) {
        if (find(v[i].begin(), v[i].end(), x) != v[i].end()) {
            ans.push_back(i);
        }
    }
        return ans;
    }
};