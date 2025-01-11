class Solution {
public:
    bool canConstruct(string s, int k) {
        int n=s.size();
        vector<int>v(26,0);
        for(int i=0;i<n;i++){
            v[s[i]-97]++;
        }
        int odd=0;
        for(auto it:v){
            if(it%2){
                odd++;
            }
        }
        if(odd<=k && n>=k){
            return true;
        }
        return false;
    }
};