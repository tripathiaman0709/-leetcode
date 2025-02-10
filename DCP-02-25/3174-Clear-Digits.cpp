class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;
        for(auto ch: s){
            if(ch >= '0' && ch <= '9' && (!st.empty())){
                st.pop();
            }
            else
                st.push(ch);
        }
        s = "";
        while(!st.empty()){
            s.push_back(st.top());
            st.pop();
        }
        reverse(s.begin(), s.end());
        return s;
        
    }
};