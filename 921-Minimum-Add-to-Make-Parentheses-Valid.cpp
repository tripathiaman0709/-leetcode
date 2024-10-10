class Solution {
public:
    int minAddToMakeValid(string s) {
        //could solve it using it a stack , but greedy approach will work faster here

        //firstly using stack
        int n=s.size();
        stack<char>st;
        int count=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push('(');
            }else{
                if(st.empty()){
                    count++;
                }else{
                    st.pop();
                }
            }
        }
        int mount=st.size();

        return count+mount;
    }
};