class Solution {
public:

    char fun(vector<char>&v,char exp){
        if(exp=='!'){
            if(v[0]=='t'){
                return 'f';
            }else{
                return 't';
            }
        }else if(exp=='&'){
            int p=0;
            for(int i=0;i<v.size();i++){
                if(v[i]=='f'){
                    p=1;
                    break;
                }
            }
            if(p){
                return 'f';
            }else{
                return 't';
            }
        }else{
            int p=0;
            for(int i=0;i<v.size();i++){
                if(v[i]=='t'){
                    p=1;
                    break;
                }
            }
            if(p){
                return 't';
            }else{
                return 'f';
            }
        }
    }

    bool parseBoolExpr(string s) {
        //using a simple data structure called STACK
        stack<char>st;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]==','){
                continue;
            }else if(s[i]==')'){
                vector<char>v;
                while(st.top()!='('){
                    v.push_back(st.top());
                    st.pop();
                }
                st.pop();//removing the openeing bracket
                char exp=st.top();
                st.pop();
                st.push(fun(v,exp));
            }else{
                st.push(s[i]);
            }
        }
        if(st.top()=='t'){
            return true;
        }else{
            return false;
        }
        
    }
};