class Solution {
public:
    string makeFancyString(string s) {
        int n=s.size();
        string ans="";
        for(int i=0;i<n-2;i++){
            if(s[i]==s[i+1] && s[i+1]==s[i+2]){
                s[i]='?';
            }
        }
        for(int i=0;i<n;i++){
            if(s[i]!='?'){
                ans+=s[i];
            }
        }
        return ans;
    }
};