1class Solution {
2public:
3
4    int M=1e9+7;
5
6    int specialTriplets(vector<int>& v) {
7        int n=v.size();
8        unordered_map<long long,long long>pre;
9        unordered_map<long long,long long>suf;
10
11        for(long long i=2;i<n;i++){
12            suf[v[i]]++;
13        }
14
15        pre[v[0]]++;
16
17        long long ans=0;
18
19        for(long long i=1;i<n;i++){
20            long long num=2*v[i];
21            if(i>1){
22                suf[v[i]]--;
23            }
24            if(pre[num] && suf[num]){
25                ans+=((pre[num]*suf[num]));
26                ans%=M;
27            }
28            pre[v[i]]++;
29            
30        }
31        return (int)ans;
32    }
33};