1class Solution {
2public:
3    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int x) {
4        int n=grid.size();
5        int m=grid[0].size();
6        vector<vector<int>>ans(n-x+1,vector<int>(m-x+1,0));
7        for(int i=0;i<=n-x;i++){
8            for(int j=0;j<=m-x;j++){
9                unordered_set<int>st;
10                for(int k=i;k<i+x;k++){
11                    for(int l=j;l<j+x;l++){
12                        st.insert(grid[k][l]);
13                    }
14                }   
15                
16                vector<int>v;
17                for(auto it:st){
18                    v.push_back(it);
19                }
20                sort(v.begin(),v.end());
21                int mini=1000001;
22
23                for(int i=0;i<v.size()-1;i++){
24                    mini=min(mini,v[i+1]-v[i]);
25                }
26                if(v.size()==1){
27                    mini=0;
28                }
29                ans[i][j]=mini;
30            }
31        }
32        return ans;
33    }
34};