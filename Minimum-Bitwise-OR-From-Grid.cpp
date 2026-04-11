1class Solution {
2public:
3    int minimumOR(vector<vector<int>>& grid) {
4        int n=grid.size();
5        int m=grid[0].size();
6        int mask=0;
7        int ans=0;
8        for(int i=20;i>=0;i--){
9            int target=mask | (1<<i);
10            bool flag1=1;
11            for(int j=0;j<n;j++){
12                bool flag2=0;
13                for(int k=0;k<m;k++){
14                    if((grid[j][k] & target)==0){
15                        flag2=1;
16                        break;
17                    }
18                }
19                if(!flag2){
20                    flag1=0;
21                    break;
22                }
23            }
24                if(flag1){
25                    mask=target;
26                }else{
27                    ans=(ans|(1<<i));
28                }
29        }
30        return ans;
31    }
32};