1class Solution {
2public:
3
4    long long M=1e9+7;
5
6    int countTrapezoids(vector<vector<int>>& v) {
7        
8
9        int n=v.size();
10        unordered_map<int,int>mppy;
11
12        for(int i=0;i<n;i++){
13            int y=v[i][1];
14            mppy[y]++;
15        }
16
17        for(auto &it:mppy){
18            int x=it.second;
19            int val = (1LL * x * (x - 1) / 2) % M;
20
21            it.second=val;
22        }
23
24        long long total=0;
25        long long ans=0;
26
27        for(auto it:mppy){
28            int y=it.second;
29            ans+=y*total;
30            ans%=M;
31            total+=y;
32            total%=M;
33        }
34
35        return (int)ans;
36    }
37};