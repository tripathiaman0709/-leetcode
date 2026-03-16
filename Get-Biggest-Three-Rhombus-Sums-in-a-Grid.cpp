1class Solution {
2public:
3    vector<int> getBiggestThree(vector<vector<int>>& grid) {
4        int m = grid.size();
5        int n = grid[0].size();
6        set<int> sums;
7
8        for(int i=0;i<m;i++){
9            for(int j=0;j<n;j++){
10                for(int d=0; d<26; d++){
11                    if(i-d<0 || j-d<0 || i+d>=m || j+d>=n) break;
12
13                    int temp = 0;
14
15                    if(d==0){
16                        temp = grid[i][j];
17                    }
18                    else{
19                        temp = grid[i-d][j] + grid[i+d][j] + grid[i][j-d] + grid[i][j+d];
20
21                        for(int t=1;t<d;t++){
22                            temp += grid[i+t][j+d-t];
23                            temp += grid[i+t][j-d+t];
24                            temp += grid[i-t][j+d-t];
25                            temp += grid[i-t][j-d+t];
26                        }
27                    }
28
29                    sums.insert(temp);
30                }
31            }
32        }
33
34        vector<int> ans(sums.begin(), sums.end());
35        sort(ans.rbegin(), ans.rend());
36
37        if(ans.size() > 3) ans.resize(3);
38        return ans;
39    }
40};