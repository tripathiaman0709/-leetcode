class Solution {
public:
    vector<int> findWordsContaining(vector<string>& v, char x) {
        int n=v.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            string s=v[i];
            for(int j=0;j<s.size();j++){
                if(s[j]==x){
                    ans.push_back(i);
                    break;
                }
            }
        }
        return ans;
    }
};