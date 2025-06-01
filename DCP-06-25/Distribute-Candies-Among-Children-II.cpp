class Solution {
public:
    long long distributeCandies(int n, int l) {
        long long ans=0;
        // int min1=max(0,n-2*l);
        // int max1=min(n,l);

        for(int i=max(0,n-2*l);i<=min(n,l);i++){
            // int N=max(0,n-i);
            // int min2=max(0,max(0,n-i)-l);
            // int max2=min(max(0,n-i),l);

            ans+=min(max(0,n-i),l)-max(0,max(0,n-i)-l)+1;
        }

        return ans;
    }
};