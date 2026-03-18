1class Solution {
2public:
3    int countSubmatrices(vector<vector<int>>& v, int k) {
4        int n = v.size(), m = v[0].size();
5        
6        vector<vector<int>> pref(n, vector<int>(m, 0));
7        int count = 0;
8
9        for(int i = 0; i < n; i++) {
10            for(int j = 0; j < m; j++) {
11                pref[i][j] = v[i][j];
12
13                if(i > 0) pref[i][j] += pref[i-1][j];
14                if(j > 0) pref[i][j] += pref[i][j-1];
15                if(i > 0 && j > 0) pref[i][j] -= pref[i-1][j-1];
16
17                if(pref[i][j] <= k) count++;
18            }
19        }
20
21        return count;
22    }
23};