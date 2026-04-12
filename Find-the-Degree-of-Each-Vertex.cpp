1class Solution {
2public:
3    vector<int> findDegrees(vector<vector<int>>& v) {
4        int n=v.size();
5        vector<int>ans(n,0);
6        for(int i=0;i<n;i++){
7            for(int j=0;j<n;j++){
8                if(v[i][j]==1){
9                    ans[j]++;
10                }
11            }
12        }
13        return ans;
14    }
15};