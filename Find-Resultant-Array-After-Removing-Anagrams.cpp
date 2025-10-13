class Solution {
public:
    vector<string> removeAnagrams(vector<string>& v) {
        int n=v.size();
        vector<string>org;
        org=v;
        for(int i=0;i<n;i++){
            string word=v[i];
            sort(word.begin(),word.end());
            v[i]=word;
        }
        vector<bool>check(n,true);
        for(int i=1;i<n;i++){
            if(v[i]==v[i-1]){
                check[i]=false;
            }
        }
        vector<string>ans;
        for(int i=0;i<n;i++){
            if(check[i]){
                ans.push_back(org[i]);
            }
        }

        return ans;
    }
};