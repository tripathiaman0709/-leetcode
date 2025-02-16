class Solution {
public:
    bool hasSpecialSubstring(string s, int k) {
        int n=s.size();
        // if(k==1){
        //     return true;
        // }
        for(int i=0;i<=n-k;i++){
            unordered_set<char>st;
            char ch;
            for(int j=i;j<i+k;j++){
                st.insert(s[j]);
                ch=s[j];
            }
            char left='?';
            char right='?';
            if(st.size()==1){
                if(i>0){
                    left=s[i-1];
                }
                if(i<n){
                    right=s[i+k];
                }

                if(ch!=left && ch!=right){
                    return true;
                }

            }
        }
        return false;
    }
};