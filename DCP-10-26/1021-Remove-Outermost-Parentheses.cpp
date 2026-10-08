class Solution {
public:
    string removeOuterParentheses(string s) {
        int n=s.size();
        int count=1;

        for(int i=1;i<n;i++){
            if(s[i]=='(' && count==0){
                s[i]='?';
                count++;
            }
            else if(s[i]=='('){
                count++;
            }
            else count--;

            if(count==0){
                s[i]='?';
            }
        }
        string ans="";
        for(int i=1;i<n;i++){
            if(s[i]!='?'){
                ans+=s[i];
            }
        }
        return ans;
    }
};