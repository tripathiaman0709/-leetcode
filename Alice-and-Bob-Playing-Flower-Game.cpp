class Solution {
public:
    long long flowerGame(int n, int m) {
        //i think the total sum should be an odd number in order for alice to win
        long long count=0;
        for(int i=1;i<=n;i++){
            if(i%2){
                //now selecting an even number from range 1 to m
                count+=m/2;
            }else{
                //now selecting an odd number from range 1 to m
                count+=(m+1)/2;
            }
        }

        return count;
    }
};