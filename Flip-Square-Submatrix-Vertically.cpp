1class Solution {
2public:
3    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& v, int x, int y, int k) {
4        int n=v.size();
5        int m=v[0].size();
6
7        vector<vector<int>>ans(k,vector<int>(k,0));
8
9        for(int i=x;i<x+k;i++){
10            for(int j=y;j<y+k;j++){
11                ans[i-x][j-y]=v[i][j];
12            }
13        }
14
15        //now reversing the rows
16
17        for(int i=x;i<x+k;i++){
18            for(int j=y;j<y+k;j++){
19                v[i][j] = ans[k - 1 - (i - x)][j - y];
20            }
21        }
22
23        return v;
24    }
25};