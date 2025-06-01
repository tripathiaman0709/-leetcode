class Solution {
public:
    long long distributeCandies(int n, int l) {
        long long ans=0;
        int min1=max(0,n-2*l);
        int max1=min(n,l);

        for(int i=min1;i<=max1;i++){
            int N=max(0,n-i);
            int min2=max(0,N-l);
            int max2=min(N,l);

            ans+=max2-min2+1;
        }

        return ans;
    }
};