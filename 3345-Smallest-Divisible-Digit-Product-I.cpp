class Solution {
public:

    int solve(int n){
        int ans=1;
        while(n){
            int dig=n%10;
            ans*=dig;
            n/=10;
        }

        return ans;
    }

    int smallestNumber(int n, int t) {
        for(int i=n;i<=100;i++){
            int num=solve(i);
            if(num%t==0){
                return i;
            }
        }

        return 0;
    }
};