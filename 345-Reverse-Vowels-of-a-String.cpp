class Solution {
public:
    string reverseVowels(string s) {
        int n=s.size();
        string forward=\\;
        vector<int>v;
        for(int i=0;i<n;i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U'){
                forward+=s[i];
                v.push_back(i);
            }
        }
        int x=0;
        for(int i=v.size()-1;i>=0;i--){
            s[v[i]]=forward[x];
            x++;
        }
        return s;
    }
};