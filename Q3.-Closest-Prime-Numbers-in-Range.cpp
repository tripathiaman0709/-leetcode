1class Solution {
2public:
3
4    vector<int>solve(int l,int r){
5        int mini=INT_MAX;
6        //using sieve of erastosthenes
7        vector<int>isprime(r+1,1);
8        isprime[0]=0;
9        isprime[1]=0;
10        //initially all are considered as primes
11        for(int i=2;i*i<=r;i++){
12            if(isprime[i]){
13                for(int j=i*i;j<=r;j+=i){
14                    isprime[j]=0;
15                    //marking it as composite
16                }
17            }
18        }
19        //now finding primes between l and r included
20        vector<int>v;
21        for(int i=l;i<=r;i++){
22            if(isprime[i])v.push_back(i);
23        }
24
25        //now finding minimum difference
26
27        if(v.size()<2){
28            return {-1,-1};
29        }
30
31        vector<int>ans;
32
33        for(int i=1;i<v.size();i++){
34            mini=min(mini,v[i]-v[i-1]);
35        }
36
37        for(int i=1;i<v.size();i++){
38            if(v[i]-v[i-1]==mini){
39                ans.push_back(v[i-1]);
40                ans.push_back(v[i]);
41                return ans;
42            }
43        }  
44        return ans; 
45    }
46
47    vector<int> closestPrimes(int l, int r) {
48        return solve(l,r);
49    }
50};