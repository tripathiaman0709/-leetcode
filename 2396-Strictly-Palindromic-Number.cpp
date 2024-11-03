class Solution {
public:

    bool pal(string s){
        int n=s.size();
        for(int i=0;i<n/2;i++){
            if(s[i]!=s[n-i-1]){
                return false;
            }
        }
        return true;
    }

    bool fun(int n,int k){
        string s="";
        while(n){
            s+=(n%k)+48;
            n/=k;
        }
        if(pal(s)){
            return true;
        }else{
            return false;
        }
    }

    bool isStrictlyPalindromic(int n) {
        for(int i=2;i<=n-2;i++){
            if(!fun(n,i)){
                return false;
            }
        }
        return true;
    }
};