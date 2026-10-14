class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        int maxsum=num*9;

        if(sum>maxsum || sum<1){
            return "";
        }
        string s="";
        for(int i=1;i<=num;i++){
            int x=min(9,sum);
            char ch=x+'0';
            s+=ch;
            
            sum-=x;
        }
        return s;
    }
};