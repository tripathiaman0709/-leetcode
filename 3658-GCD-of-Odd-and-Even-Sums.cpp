class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int oddgcd=n*n;
 
        int evengcd=(n*(n+1));

        int ans=gcd(oddgcd,evengcd);

        return ans;
    }
};