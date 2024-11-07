class Solution {
public:
    string mergeAlternately(string s1, string s2) {
        string ans="";
        int z=max((int)s1.size(),(int)s2.size());
        for(int i=0;i<z;i++){
            if(i<(int)s1.size()){
                ans+=s1[i];
            }
            if(i<(int)s2.size()){
                ans+=s2[i];
            }
        }
        return ans;
    }
};