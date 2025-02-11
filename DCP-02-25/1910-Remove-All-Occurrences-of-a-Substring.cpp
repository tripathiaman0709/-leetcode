class Solution {
public:
    string removeOccurrences(string s, string x) {
        int n=s.size();
        int sz=x.size();
        int i=0;
        char ch=x[sz-1];
        while(i<n){
            if(s[i]==ch && i+1>=sz){
                string z="";
                int newi=i-sz+1;
                for(int j=newi;j<=i;j++){
                    z+=s[j];
                }
                if(z==x){
                    i=newi-1;
                    s.erase(newi,sz);                    
                }
            }
            i++;
        }
        return s;
    }
};