class Solution {
public:
    int minimumOneBitOperations(int num) {
        if(num==0){
            return 0;
        }
        int x=0;
        while((1<<x)<=num){
            x++;
        }
        x--;
        return (1<<x+1)-1-minimumOneBitOperations((1<<x)^num);
    }
};