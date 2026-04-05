1class Solution {
2public:
3    string decodeCiphertext(string s, int r) {
4        if(r == 0) return "";
5
6        int n = s.size();
7        int m = n / r;
8
9        vector<vector<char>> grid(r, vector<char>(m));
10
11        int idx = 0;
12        for(int i = 0; i < r; i++){
13            for(int j = 0; j < m; j++){
14                grid[i][j] = s[idx++];
15            }
16        }
17
18        string ans = "";
19
20        for(int d = 0; d < m; d++){
21            int i = 0, j = d;
22            while(i < r && j < m){
23                ans += grid[i][j];
24                i++, j++;
25            }
26        }
27
28        while(!ans.empty() && ans.back() == ' ') ans.pop_back();
29
30        return ans;
31    }
32};