class Solution {
public:
    int minOperations(string s) {
        int n=s.size();
        if(n==1){
            return 0;
        }
        if(n==2){
            string str=s;
            sort(s.begin(),s.end());
            if(str==s){
                return 0;
            }else{
                return -1;
            }
        }
        string str=s;
        sort(s.begin(),s.end());

        //if starting 1 or last 1 letters are in decreasing order then answer is 1 else 2
        if(s==str){
            return 0;
        }
        else if((str[0]==s[0]) || (str[n-1]==s[n-1])){
            return 1;
        }

        string x=str;

        sort(str.begin()+1,str.end());
        sort(str.begin(),str.end()-1);

        sort(x.begin(),x.end()-1);
        sort(x.begin()+1,x.end());
        

        if(str==s || x==s){
            return 2;
        }


        return 3;
    }
};