class Solution {
public:
    int maximum69Number (int num) {
        string s=to_string(num);
        int n=s.size();

        int first6=-1;

        for(int i=0;i<n;i++){
            if(s[i]=='6'){
                first6=i;
                break;
            }
        }

        if(first6!=-1){
            s[first6]='9';
        }

        int ans=stoi(s);

        return ans;
    }
};