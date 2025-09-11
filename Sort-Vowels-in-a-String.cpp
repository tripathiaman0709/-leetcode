class Solution {
public:
    string sortVowels(string s) {
        int n=s.size();
        vector<int>ind;
        vector<int>ch;
        for(int i=0;i<n;i++){
            if(s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U' || s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
                ind.push_back(i);
                ch.push_back(s[i]);
            }
        }
        sort(ch.begin(),ch.end());
        string ans=s;
        int x=0;
        for(auto it:ind){
            ans[it]=ch[x];
            x++;
        }

        return ans;
    }
};