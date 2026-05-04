1class Solution {
2public:
3    void rotate(vector<vector<int>>& grid) {
4        //n * n grid
5        int n=grid.size();
6        vector<vector<int>>ans(n,vector<int>(n,0));
7        for(int i=n-1;i>=0;i--){
8            for(int j=0;j<n;j++){
9                ans[j][i]=grid[i][j];
10            }
11        }
12        for(int i=0;i<n;i++){
13            for(int j=0;j<n;j++){
14                grid[i][j]=ans[i][abs(j-n+1)%(n)];
15            }
16        }
17    }
18};