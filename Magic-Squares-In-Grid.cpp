1class Solution {
2public:
3
4    int magic(int r,int c,vector<vector<int>>& grid){
5        int rsum=0;
6        int csum=0;
7
8        set<int>st;
9        st.clear();
10        //all elements 1-9 present
11        for(int i=r;i<=r+2;i++){
12            for(int j=c;j<=c+2;j++){
13                if(grid[i][j]>9 || grid[i][j]<1){
14                    return 0;
15                }
16                st.insert(grid[i][j]);
17            }
18        }
19        if(st.size()<9){
20            return 0;
21        }        
22
23
24        //row sum
25        for(int i=r;i<r+3;i++){
26            for(int j=c;j<c+3;j++){
27                rsum+=grid[i][j];
28            }
29            if(rsum!=15){
30                return 0;
31            }
32            rsum=0;
33        }
34        //col sum
35        for(int i=c;i<c+3;i++){
36            for(int j=r;j<r+3;j++){
37                csum+=grid[j][i];
38            }
39            if(csum!=15){
40                return 0;
41            }
42            csum=0;
43        }
44        //diagonal sum
45        if(grid[r][c]+grid[r+1][c+1]+grid[r+2][c+2]!=15 || grid[r][c+2]+grid[r+1][c+1]+grid[r+2][c]!=15){
46            return 0;   
47        }
48
49        return 1;
50
51    }
52
53
54    int numMagicSquaresInside(vector<vector<int>>& grid) {
55        int row=grid.size();
56        int col=grid[0].size();
57        int ans=0;
58        for(int r=0;r<row-2;r++){
59            for(int c=0;c<col-2;c++){
60                ans+=magic(r,c,grid);
61            }
62        }
63        return ans;
64    }
65};