1class Solution {
2public:
3
4    int solve(int i,int j,int k,vector<vector<int>>&v,vector<vector<vector<int>>>&dp){
5        int n=v.size();
6        int m=v[0].size();
7
8        //base case
9        if(i==n-1 && j==m-1){
10            if(v[i][j]<0 && k>0){
11                //we wont pick the value and nuetralize it
12                return 0;
13            }else{
14                return v[i][j];
15            }
16        }
17        
18        //out of bounds case
19        if(i>n-1 || j>m-1){
20            return INT_MIN;
21        }
22
23        if(dp[i][j][k]!=INT_MIN){
24            return dp[i][j][k];
25        }
26        
27            int pick=v[i][j]+max(solve(i+1,j,k,v,dp),solve(i,j+1,k,v,dp));
28        
29            int notpick=INT_MIN;
30            if(v[i][j]<0 && k>0){
31                int down=solve(i+1,j,k-1,v,dp);
32                int right=solve(i,j+1,k-1,v,dp);
33
34                notpick=max(down,right);
35            }
36        return dp[i][j][k]=max(pick,notpick);
37    }
38
39    int maximumAmount(vector<vector<int>>& v) {
40        int n=v.size();
41        int m=v[0].size();
42        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(3, INT_MIN)));     
43           return solve(0,0,2,v,dp);
44    }
45};