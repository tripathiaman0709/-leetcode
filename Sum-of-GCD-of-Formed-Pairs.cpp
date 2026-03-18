1class Solution {
2public:
3
4    long long hcf(long long a, long long b) {
5        if (b == 0) return a;
6        return hcf(b, a % b);
7    }
8
9    long long gcdSum(vector<int>& v) {
10        long long n=v.size();
11        long long maxi=0;
12        vector<long long>maxv(n,0);
13
14        for(long long i=0;i<n;i++){
15            if(maxi<v[i]){
16                maxi=v[i];
17            }
18            maxv[i]=maxi;
19        }
20        vector<long long>pre;
21        for(long long i=0;i<n;i++){
22            long long x=hcf(v[i],maxv[i]);
23            pre.push_back(x);
24        }
25
26        sort(pre.begin(),pre.end());
27        long long sum=0;
28        for(long long i=0;i<pre.size()/2;i++){
29            long long val=gcd(pre[i],pre[pre.size()-i-1]);
30
31            sum+=val;
32        }
33        return sum;
34    }
35};