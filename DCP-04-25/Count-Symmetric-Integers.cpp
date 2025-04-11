class Solution {
public:
    bool fun(int n){
        string s=to_string(n);

        int sz=s.size();
        if(sz%2){
            return false;
        }
        int sum1=0;
        int sum2=0;
        for(int i=0;i<sz/2;i++){
            sum1+=s[i]-'0';
        }
        for(int i=sz/2;i<sz;i++){
            sum2+=s[i]-'0';
        }

        return (sum1==sum2);
    }

    int countSymmetricIntegers(int low, int high) {
        //simple 
        //converting to string then calculating 
        //if matches then increasing the count
        //returing it as answer
        int count=0;
        for(int i=low;i<=high;i++){
            if(fun(i)){
                count++;
            }
        }

        return count;
    }
};