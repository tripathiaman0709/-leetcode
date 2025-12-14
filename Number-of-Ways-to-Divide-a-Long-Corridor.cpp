1class Solution {
2public:
3    int numberOfWays(string s) {
4        int n=s.size();
5        int M=1000000007;
6        vector<int>pre(n+1,0);
7        vector<int>v(n,0);
8        pre[0]=0;
9        for(int i=0;i<n;i++){
10            if(s[i]=='S'){
11                v[i]=1;
12            }
13        }
14        for(int i=1;i<=n;i++){
15            pre[i]=pre[i-1]+v[i-1];
16        }
17        int final=pre[n];
18        if(final%2){
19            return 0;
20        }
21        long long count=1;
22        unordered_map<int,int>mpp;
23        for(int i=1;i<=n;i++){
24            mpp[pre[i]]++;
25        }
26        bool billu=false;
27        for(auto it:mpp){
28            if(it.first % 2 == 0 && it.first!=0 && it.first!=final){
29                count=(count*it.second)%M;
30                billu=true;
31            }
32        }
33        if(!billu){
34            if(final>=2){
35                return 1;
36            }
37            return 0;
38        }
39        return (int)count;
40    }
41};