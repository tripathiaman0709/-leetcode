1class Solution {
2public:
3    double solve(int i,int j,int k,vector<vector<double>>&dp){
4        if(i<0 || j<0 || j>i) return 0.0;
5
6        if(i==0 && j==0)
7            return k;
8
9        if(dp[i][j] != -1)
10            return dp[i][j];
11
12        double left = solve(i-1,j-1,k,dp);
13        double right = solve(i-1,j,k,dp);
14
15        double fromLeft = max(0.0,(left-1)/2.0);
16        double fromRight = max(0.0,(right-1)/2.0);
17
18        return dp[i][j] = fromLeft + fromRight;
19    }
20
21    double champagneTower(int k, int r, int c) {
22        vector<vector<double>> dp(r+1, vector<double>(r+1,-1));
23        return min(1.0, solve(r,c,k,dp));
24    }
25};
26