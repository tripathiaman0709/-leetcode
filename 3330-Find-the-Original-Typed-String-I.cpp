class Solution {
public:
    int possibleStringCount(string s) {
        int n=s.size();
        
        int count=1;
        int pos=0;
        for(int i=n-1;i>0;i--){
            if(s[i]==s[i-1]){
                count++;
            }else{
                pos=i;
                break;
            }
        }

        for(int i=0;i<pos;i++){
            if(s[i]==s[i+1]){
                count++;
            }
        }
        return count;        
    }
};