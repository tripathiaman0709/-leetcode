1class Solution {
2public:
3    int countNegatives(vector<vector<int>>& grid) {
4        int n=grid.size();
5        int m=grid[0].size();
6        int count=0;
7        for(int i=0;i<n;i++){
8            for(int j=0;j<m;j++){
9                if(grid[i][j]<0){
10                    count++;
11                }
12            }
13        }
14        return count;
15    }
16};