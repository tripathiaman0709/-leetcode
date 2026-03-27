1class Solution {
2public:
3    bool areSimilar(vector<vector<int>>& mat, int k) {
4        int n=mat.size();
5        int m=mat[0].size();
6
7        vector<vector<int>>v(n,vector<int>(m,0));
8        for(int i=0;i<n;i++){
9            for(int j=0;j<m;j++){
10                v[i][j]=mat[i][(j+k)%m];
11            }
12        }
13
14        return (mat==v);
15    }
16};