1class Solution {
2public:
3    long long maxProfit(vector<int>& v, vector<int>& s, int k) {
4        int n=v.size();
5        
6        long long maxprofit=0;
7        vector<long long>profit(n,0);
8
9        for(long long i=0;i<n;i++){
10            profit[i]=(s[i]*v[i]);
11            maxprofit+=profit[i];
12        }
13
14        long long actual=0;
15        long long modify=0;
16        long long maxgain=0;
17
18        long long i=0;
19        long long j=0;
20
21        while(j<n){
22            actual+=profit[j];
23            if(j-i+1>k/2){
24                modify+=(v[j]);
25            }
26            if(j-i+1>k){
27                actual-=profit[i];
28                modify-=v[i+k/2];
29                i++;
30            }
31            if(j-i+1==k){
32                maxgain=max(maxgain,modify-actual);
33            }
34            j++;
35        }
36        return maxprofit+maxgain;
37    }
38};