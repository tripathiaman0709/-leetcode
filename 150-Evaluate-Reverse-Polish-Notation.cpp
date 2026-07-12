class Solution {
public:
    int evalRPN(vector<string>& s) {
        int n=s.size();
        stack<string>st;

        for(int i=0;i<n;i++){
            if(s[i]=="+"){
                int x1=stoi(st.top());
                st.pop();
                int x2=stoi(st.top());
                st.pop();

                int val=x1+x2;

                st.push(to_string(val));
            }
            else if(s[i]=="-"){
                int x1=stoi(st.top());
                st.pop();
                int x2=stoi(st.top());
                st.pop();

                int val=x2-x1;

                st.push(to_string(val));
            }
            else if(s[i]=="*"){
                int x1=stoi(st.top());
                st.pop();
                int x2=stoi(st.top());
                st.pop();

                int val=x1*x2;

                st.push(to_string(val));
            }
            else if(s[i]=="/"){
                int x1=stoi(st.top());
                st.pop();
                int x2=stoi(st.top());
                st.pop();

                int val=x2/x1;

                st.push(to_string(val));
            }
            else{
                st.push(s[i]);
            }
        }

        //now st.top would contain answer

        int ans=stoi(st.top());
        return ans;
    }
};