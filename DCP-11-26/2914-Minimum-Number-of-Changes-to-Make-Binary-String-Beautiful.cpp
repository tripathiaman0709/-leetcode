class Solution {
public:
    int minChanges(string s) {
        int n=s.size();
        if(n==2){
            if(s[0]!=s[1]){
                return 1;
            }else{
                return 0;
            }
        }
        int x=0;
        for(int i=0;i<n-1;i+=2){
            if(s[i]!=s[i+1]){
                x++;
            }
        }
        return x;
    }
};