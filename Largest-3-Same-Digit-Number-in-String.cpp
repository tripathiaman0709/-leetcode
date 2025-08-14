class Solution {
public:
    string largestGoodInteger(string s) {
        int n=s.size();
        string maxi="000";
        bool found=false;
        for(int i=0;i<n-2;i++){
            if(s[i]==s[i+1] && s[i+1]==s[i+2]){
                found=true;
                string num="";
                num+=s[i];
                num+=s[i+1];
                num+=s[i+2];

                if(num>maxi){
                maxi=num;
                }
            }
        }
        if(found){
            return maxi;
        }else{
            return "";
        }
    }
};