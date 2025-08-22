class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        int minrow=1001;
        int maxrow=-1;
        int mincol=1001;
        int maxcol=-1;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    mincol=min(mincol,j);
                    maxcol=max(maxcol,j);
                    minrow=min(minrow,i);
                    maxrow=max(maxrow,i);
                }
            }
        }

        if(minrow==1001 || maxrow==-1 || mincol==1001 || maxcol==-1){
            return 0;
        }

        int d1=maxcol-mincol+1;
        int d2=maxrow-minrow+1;

        int ans=d1*d2;

        return ans;
    }
};