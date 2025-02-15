class Solution {
public:

    int fun(int sq,int currsum,int num){
        if(sq==0){
            return (num==currsum);
        }
        return fun(sq/10,currsum+sq%10,num) || fun(sq/100,currsum+sq%100,num) || fun(sq/1000,currsum+sq%1000,num) || fun(sq/10000,currsum+sq%10000,num);
    }

    int punishmentNumber(int n) {
        //simple recursion
        int punishment=0;
        for(int i=1;i<=n;i++){
            int sq=i*i;
            if(fun(sq,0,i)){
                punishment+=sq;
            }
        }
        return punishment;
    }
};