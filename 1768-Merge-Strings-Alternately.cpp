class Solution {
public:
    string mergeAlternately(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();

        int z=min(n,m);

        int l=0;
        string ans="";

        while(l<z){
            ans+=s1[l];
            ans+=s2[l];
            l++;
        }       
        string x=s1.substr(l);
        ans+=x;
        string y=s2.substr(l);
        ans+=y;

        return ans;


    }
};