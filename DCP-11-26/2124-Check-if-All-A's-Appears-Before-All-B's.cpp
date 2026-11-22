class Solution {
public:
    bool checkString(string s) {
        int n=s.size();
        int counta=0;
        int countb=0;

        for(auto it:s){
            if(it=='a'){
                counta++;
            }
        }
        countb=n-counta;

        for(int i=0;i<n;i++){
            if(s[i]=='a'){
                counta--;
            }else{
                if(counta>0){
                    return false;
                }
            }
        }

        return true;
    }
};