class Solution {
public:
    int ans;
    int noobs;
    void fun(int i,int j,vector<vector<int>>& grid,int count){
        int n=grid.size();
        int m=grid[0].size();
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]==-1){
            return;
        }
        if(grid[i][j]==2){
            if(count==noobs){
                ans++;
            }
            return;
        }
        grid[i][j]=-1;
        int delrow[4]={1,0,-1,0};
        int delcol[4]={0,1,0,-1};

        for(int k=0;k<4;k++){
            int r=delrow[k]+i;
            int c=delcol[k]+j;

            fun(r,c,grid,count+1);
        }

        grid[i][j]=0;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int six;
        int siy;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    six=i;
                    siy=j;
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    noobs++;
                }
            }
        }
        noobs++;
        //adding one extra as the start box is also not an obstruction
        int count=0;
        fun(six,siy,grid,count);

        return ans;
    }
};