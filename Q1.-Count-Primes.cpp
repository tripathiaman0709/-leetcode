1class Solution {
2public:
3
4    int sieve(int n){
5        int count=0;
6        vector<int>isprime(n+1,1);
7        //n numbers and sb prime hai
8        for(int i=2;i*i<=n;i++){
9            if (isprime[i]) {
10                for (int j = i * i; j <= n; j += i) {
11                    isprime[j] = 0;
12                }
13            }
14        }
15
16        for(int i=2;i<=n;i++){
17            if(isprime[i])count++;
18        }
19        return count;
20    }
21
22    int countPrimes(int n) {
23        if(n<2) return 0;
24        //using seive of erastosthenes to find the prime numbers less than equal to n        
25        return sieve(n-1);
26    }
27};