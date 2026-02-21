1class Solution {
2public:
3
4    bool fun(int n){
5        if(n<=1)return false;
6        for(int i=2;i*i<=n;i++){
7            if(n%i==0) return false;
8        }
9        return true;
10    }
11
12    int countPrimeSetBits(int a, int b) {
13        int ans=0;
14        for(int i=a;i<=b;i++){
15            int x=__builtin_popcount(i);
16            if(fun(x))ans++;
17        }
18        return ans;
19    }
20};