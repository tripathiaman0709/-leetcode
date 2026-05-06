1class Solution {
2public:
3    vector<vector<char>> rotateTheBox(vector<vector<char>>& grid) {
4        int n=grid.size();
5        int m=grid[0].size();
6
7        for(int i=0;i<n;i++){
8            for(int j=m-2;j>=0;j--){
9                if(grid[i][j]=='#'){
10                    int right=j+1;
11                    bool billu=false;
12                    while(right <m && grid[i][right]=='.'){
13                        right++;
14                        billu=true;
15                    }
16                    if(billu){
17                        grid[i][right-1]='#';
18                        grid[i][j]='.';
19                    }
20                }
21            }
22        }
23
24        vector<vector<char>>ans(m,vector<char>(n,'.'));
25
26        for(int i=0;i<n;i++){
27            for(int j=0;j<m;j++){
28                ans[j][n-i-1]=grid[i][j];
29            }
30        }
31
32        return ans;
33    }
34};