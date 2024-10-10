class Solution {
public:
    int minLength(string s) {
        int n=s.size();
        stack<char>st;
        for(int i=0;i<n;i++){
            if(s[i]=='B'){
                ;
                if(!st.empty() && st.top()=='A'){
                    st.pop();
                }else{
                    st.push('B');
                }
            }
            else if(s[i]=='D'){
                if(!st.empty() && st.top()=='C'){
                    st.pop();
                }else{
                    st.push('D');
                }
            }else{
                st.push(s[i]);
            }
        }
        int ans=st.size();
        return ans;
    }
};