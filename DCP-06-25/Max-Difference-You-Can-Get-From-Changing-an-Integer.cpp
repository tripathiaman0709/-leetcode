class Solution {
public:
    int maxDiff(int num) {
        string s=to_string(num);
        string s1=s;

        int n=s.size();
        char maxi='?';
        for(int i=0;i<n;i++){
            if(s[i]!='9'){
                maxi=s[i];
                break;
            }
        }
        for(int i=0;i<n;i++){
            if(s[i]==maxi){
                s[i]='9';
            }
        }

        char mini='?';
        if(s1[0]=='1'){
            for(int i=1;i<n;i++){
                if(s1[i]>'1'){
                    mini=s1[i];
                    break;
                }
            }
            for(int i=0;i<n;i++){
                if(s1[i]==mini){
                    s1[i]='0';
                }
            }
        }else{
            char ch=s1[0];
            for(int i=0;i<n;i++){
                if(s1[i]==ch){
                    s1[i]='1';
                }
            }
        }

        int maxii=stoi(s);
        int minii=stoi(s1);

        return maxii-minii;        
    }
};