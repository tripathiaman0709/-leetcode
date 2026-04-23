1class Solution {
2public:
3    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
4        vector<vector<int>> grid(n, vector<int>(m, 0));
5        queue<pair<int,int>> q;
6
7        //mark the already colored one
8        int total_colored=0;
9        for(auto &s : sources){
10            int r = s[0], c = s[1], color = s[2];
11            grid[r][c] = color;
12            total_colored++;
13            q.push({r,c});
14        }
15
16        vector<int> dr = {1,-1,0,0};
17        vector<int> dc = {0,0,1,-1};
18
19        while(!q.empty() && total_colored < m*n){
20            int size = q.size();
21            map<pair<int,int>, int> updates;
22
23            while(size--){
24                auto [r,c] = q.front();
25                q.pop();
26
27                for(int k=0;k<4;k++){
28                    int nr = r + dr[k];
29                    int nc = c + dc[k];
30
31                    if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==0){
32                        updates[{nr,nc}] = max(updates[{nr,nc}], grid[r][c]);
33                    }
34                }
35            }
36
37            for(auto &it : updates){
38                int r = it.first.first;
39                int c = it.first.second;
40                grid[r][c] = it.second;
41                total_colored++;
42                q.push({r,c});
43            }
44        }
45
46        return grid;
47    }
48};