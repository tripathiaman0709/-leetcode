1class Solution {
2public:
3    int solve(int ind, vector<int>& v, int k, int sz, int xoro,vector<vector<vector<int>>>&dp) {
4        int n = v.size();
5
6        // Base case: processed all elements
7        if (ind == n) {
8            if (xoro == k) return sz;
9            return -1e9; // impossible case
10        }
11        if(dp[ind][sz][xoro]!=-1){
12            return dp[ind][sz][xoro];
13        }
14        // pick
15        int pick = solve(ind + 1, v, k, sz + 1, xoro ^ v[ind],dp);
16
17        // not pick
18        int notpick = solve(ind + 1, v, k, sz, xoro,dp);
19
20        return dp[ind][sz][xoro]=max(pick, notpick);
21    }
22
23    int minRemovals(vector<int>& v, int k) {
24        int n = v.size();
25        vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(16384,-1)));
26        int maxSize = solve(0, v, k, 0, 0,dp);
27
28        if (maxSize < 0) return -1; // no valid subset
29        return n - maxSize;
30    }
31};