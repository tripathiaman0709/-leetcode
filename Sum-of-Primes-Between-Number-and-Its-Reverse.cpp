1class Solution {
2public:
3
4    //now using seive of erastosthenes to find the primes in log(log(n)) time
5    void solve(int n,vector<int>&isprime){
6        
7        for(int i=2;i*i<=n;i++){
8            if(isprime[i]==1){
9                for(int j=i*i;j<=n;j+=i){
10                    isprime[j]=0;
11                }
12            }
13        }
14    }
15
16    int sumOfPrimesInRange(int n) {
17        string s=to_string(n);
18        reverse(s.begin(),s.end());
19        int rev=stoi(s);
20
21        int maxi=max(rev,n);
22        int mini=min(rev,n);
23        int sum=0;
24        vector<int>isprime(maxi+1,1);
25        isprime[0]=isprime[1]=0;
26        solve(maxi,isprime);
27        for(int i=mini;i<=maxi;i++){
28            if(isprime[i]){
29                sum+=i;
30            }
31        }
32        return sum;
33    }
34};