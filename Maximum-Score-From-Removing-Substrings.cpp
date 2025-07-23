class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int n=s.size();
        int sum1=0;
        int sum2=0;
        if(x<=y){
            stack<char>st;
            for(int i=0;i<n;i++){
                if(s[i]=='a' && st.size()>0 &&  st.top()=='b'){
                    st.pop();
                    sum1+=y;
                }else{
                    st.push(s[i]);
                }
            }
            stack<char>stt;
            while(st.size()){
                char c=st.top();
                st.pop();
                if(c=='a' && stt.size()>0 && stt.top()=='b'){
                    sum1+=x;
                    stt.pop();
                }else{
                    stt.push(c);
                }
            }         
            return sum1;
        }else{
            stack<char>st2;
            for(int i=0;i<n;i++){
                if(s[i]=='b' && st2.size()>0 && st2.top()=='a'){
                    st2.pop();
                    sum2+=x;
                }else{
                    st2.push(s[i]);
                }
            }
            stack<char>stt2;
            while(st2.size()){
                char ch=st2.top();
                st2.pop();
                if(ch=='b' && stt2.size()>0 && stt2.top()=='a'){
                    sum2+=y;
                    stt2.pop();
                }else{
                    stt2.push(ch);
                }
            }         
            return sum2;
        }
    }
};