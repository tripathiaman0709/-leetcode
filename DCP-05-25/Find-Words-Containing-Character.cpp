class Solution {
public:
    vector<int> findWordsContaining(vector<string>& v, char x) {
        int n=v.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            string s=v[i];
            sort(s.begin(),s.end());
            if(binary_search(s.begin(),s.end(),x)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};