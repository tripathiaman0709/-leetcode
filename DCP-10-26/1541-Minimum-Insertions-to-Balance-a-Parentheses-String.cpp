class Solution {
public:
    int minInsertions(string s) {
        int cnt = 0;
        vector<char>st;
        for(int i = 0; i<s.size(); i++){
            if(s[i]=='('){
                st.push_back('(');
            }
            else{
                if(i+1<s.size() && s[i+1]==')'){
                    if(!st.empty()){
                        st.pop_back();
                    }
                    else{
                        cnt++;
                    }
                    i++;
                }
                else if(!st.empty()){
                    st.pop_back();
                    cnt++;
                }
                else{
                    cnt+=2;
                }
            }
        }
        cnt += 2*st.size();
        return cnt;
    }
};