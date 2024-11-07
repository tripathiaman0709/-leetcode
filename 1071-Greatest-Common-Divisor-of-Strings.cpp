class Solution {
public:

    bool fun(int i,int n,int m,string s1,string s2){
        if(n%i || m%i){
            return false;
        }
        int f1=n/i;
        int f2=m/i;

        string x=s1.substr(0,i);

        string a="";
        string b="";

        for(int k=0;k<f1;k++){
            a+=x;
        }
        for(int k=0;k<f2;k++){
            b+=x;
        }

        return (a==s1 && b==s2);
    }

    string gcdOfStrings(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        string empty="";
        for(int i=min(n,m);i>0;i--){
            if(fun(i,n,m,s1,s2)){
                return s1.substr(0,i);
            }
        }
        return empty;

        
    }
};