class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();

        if(n!=m){
            return false;
        }

        string a="";
        string b="";

        for(int i=0;i<n;i++){
            if(s1[i]!=s2[i]){
                a+=s1[i];
                b+=s2[i];
            }
        }

        if(a.size()==0 || (a.size()==2 && a[1]==b[0] && a[0]==b[1])){
            return true;
        }
        return false;
    }
};