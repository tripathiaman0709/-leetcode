1class Solution {
2public:
3    vector<vector<int>> rotate(vector<vector<int>>& mat) {
4        int n = mat.size();
5        vector<vector<int>> res(n, vector<int>(n));
6        
7        for(int i = 0; i < n; i++) {
8            for(int j = 0; j < n; j++) {
9                res[j][n - i - 1] = mat[i][j];
10            }
11        }
12        return res;
13    }
14
15    bool findRotation(vector<vector<int>>& v1, vector<vector<int>>& v2) {
16        for(int i = 0; i < 4; i++) {
17            if(v1 == v2) return true;
18            v1 = rotate(v1);
19        }
20        return false;
21    }
22};