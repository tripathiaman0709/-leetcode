class Solution {
public:

    void fun(int n,string &s,int open,int close,vector<string>&ans){
        if(s.size()==2*n){
            ans.push_back(s);
            return;
        }

        if(open<n){
            //if open < n then only we will add up the opening bracket
            s.push_back('(');
            fun(n,s,open+1,close,ans);
            s.pop_back();
        }
        if(close<open){
            //adding close bracket only and only if close < open
            s.push_back(')');
            fun(n,s,open,close+1,ans);
            s.pop_back();
        }
        //in backtracking

        //do
        //explore
        //undo        
    }

    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string s=\\;
        fun(n,s,0,0,ans);

        return ans;
    }
};