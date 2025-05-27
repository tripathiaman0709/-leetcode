class Solution {
public:
    int differenceOfSums(int n, int m) {
        int total=n*(n+1);
        total/=2;

        //total sum from 1 to n
        int div=0;
        for(int i=m;i<=n;i+=m){
            div+=i;
        }

        int big=total-div;
        return big-div;
    }
};