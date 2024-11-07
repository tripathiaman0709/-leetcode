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
        if(z==m){      
        for(int i=z;i<n;i++){
            ans+=s1[i];
        }
        }else{
        for(int i=z;i<m;i++){
            ans+=s2[i];
        }
        }
        return ans;


    }
};