class Solution {
public:
    bool canBeValid(string s, string l) {
        //trying easy and simpler way
        //two way traversal
        //from left to right
        //and from right to right
        int n=s.size();
        if(n%2){
            return false;
        }
        int count1=0;
        for(int i=0;i<n;i++){
            if(l[i]=='0'){
                count1++;
            }
            else if(s[i]=='('){
                count1++;
            }
            else if(s[i]==')'){
                count1--;
            }
            if(count1<0){
                return false;
            }
        }
        int count2=0;
        for(int i=n-1;i>=0;i--){
            if(l[i]=='0'){
                count2++;
            }
            else if(s[i]==')'){
                count2++;
            }else if(s[i]=='('){
                count2--;
            }
            if(count2<0){
                return false;
            }
        }
        return true;
    }
};