class Solution {
public:
    bool isCircularSentence(string s) {
        int n=s.size();
        vector<char>start;
        vector<char>end;
        int count=0;
        for(int i=0;i<n;i++){
            if(s[i]==' '){
                start.push_back(s[i+1]);
                end.push_back  (s[i-1]);
                count++;
            }
        }

        for(int i=0;i<start.size();i++){
            if(start[i]!=end[i]){
                return false;
            }
        }
            if(s[0]==s[n-1]){
                return true;
            }else{
                return false;
            }
            
        return true;
    }
};