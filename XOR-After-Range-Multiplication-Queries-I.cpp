1class Solution {
2public:
3    int xorAfterQueries(vector<int>& v, vector<vector<int>>& q) {
4        int n=v.size();
5        int sz=q.size();
6        int MOD=1e9+7;
7
8        for(int i=0;i<sz;i++){
9            long long l=q[i][0];
10            long long r=q[i][1];
11            long long k=q[i][2];
12            long long vi=q[i][3];
13            long long ind=l;
14            while(ind<=r){
15                v[ind]=(v[ind]*vi)%MOD;
16                ind+=k;
17            }
18        }
19        int xoro=0;
20        for(int i=0;i<n;i++){
21            xoro^=v[i];
22        }
23
24        return xoro;
25    }
26};