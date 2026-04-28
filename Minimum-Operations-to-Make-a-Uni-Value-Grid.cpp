1class Solution {
2public:
3    int minOperations(vector<vector<int>>& grid, int x) {
4        int n=grid.size();
5        int m=grid[0].size();
6
7        vector<int>v;
8        for(int i=0;i<n;i++){
9            for(int j=0;j<m;j++){
10                v.push_back(grid[i][j]);
11            }
12        }
13
14        sort(v.begin(),v.end());
15
16        int sz=v.size();
17
18        //ya toh brute force laga ke each element ke barabar lane ki koshish kro
19
20        //ya middle element ke barabar bnane ki
21
22        int mid1=v[sz/2];
23        int mid2=v[max(0,sz/2 - 1)];
24
25        int ans1=-1;
26        int sum1=0;
27        for(int i=0;i<sz;i++){
28            if(abs(mid1-v[i])%x){
29                sum1=-1;
30                break;
31            }else{
32                sum1+=abs(mid1-v[i])/x;
33            }
34        }
35
36        int sum2=0;
37        for(int i=0;i<sz;i++){
38            if(abs(mid2-v[i])%x){
39                sum2=-1;
40                break;
41            }else{
42                sum2+=abs(mid2-v[i])/x;
43            }
44        }
45
46        if(sum1==-1 && sum2==-1){
47            return -1;
48        }
49
50        return min(sum1,sum2);
51    }
52};