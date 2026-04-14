1class Solution {
2public:
3
4    long long solve(int robotind,int factind,vector<int>&r,vector<int>&v,vector<vector<long long>>&dp){
5        //if all robots are visited - base case
6        if(robotind>=r.size())return 0;
7        //if all factories are visited before robot being fixed
8        if(factind>=v.size())return 1e18;
9
10        if(dp[robotind][factind]!=-1){
11            return dp[robotind][factind];
12        }
13
14        //now pick and not pick cases
15        long long pick=abs(r[robotind]-v[factind])+solve(robotind+1,factind+1,r,v,dp);
16        long long notpick=solve(robotind,factind+1,r,v,dp);
17
18        return dp[robotind][factind]=min(pick,notpick);
19    }
20
21    long long minimumTotalDistance(vector<int>& r, vector<vector<int>>& f) {
22        int n=r.size();
23        sort(r.begin(),r.end());
24        sort(f.begin(),f.end());
25        int m=f.size();
26        vector<int>v;
27        for(int i=0;i<m;i++){
28            int val=f[i][0];
29            int times=f[i][1];
30            for(int x=0;x<times;x++){
31                v.push_back(val);
32            }
33        }
34        vector<vector<long long>>dp(n+1,vector<long long>(v.size()+1,-1));
35        return solve(0,0,r,v,dp);
36    }
37};