class Solution {
public:
    int minSwaps(string s) {
        int n=s.size();
        stack<char>st;
        int count=0;
        for(int i=0;i<n;i++){
            if(s[i]==']'){
                if(st.empty()){
                    count++;
                }else{
                    st.pop();
                }
            }else{
                st.push('[');
            }
        }
        int ans=(count+1)/2;
        return ans;
    }
};