class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.size();
        int maxi=0;

        int open=0;
        int close=0;

        for(int i=0;i<n;i++){
            if(s[i]=='('){
                open++;
            }else{
                close++;
            }

            if(open==close){
                maxi=max(maxi,open+close);
            }
            if(close>open){
                close=0;
                open=0;
            }
            // if(open>close){
            //     maxi=max(maxi,close+close);
            // }
        }

        //now right to left traversal

        int op=0;
        int cl=0;

        for(int i=n-1;i>=0;i--){
            if(s[i]=='('){
                op++;
            }else{
                cl++;
            }

            if(op==cl){
                maxi=max(maxi,op+cl);
            }
            if(op>cl){
                cl=0;
                op=0;
            }
        }        

        return maxi;
    }
};