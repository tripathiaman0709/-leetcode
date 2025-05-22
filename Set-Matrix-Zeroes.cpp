class Solution {
public:
    void setZeroes(vector<vector<int>>& grid) {
        //first row and first column ko alag se check kro
        //edge case avoid krne ke liye

        int n=grid.size();
        int m=grid[0].size();
        bool r=false;
        bool c=false;
        for(int i=0;i<n;i++){
            if(grid[i][0]==0){
                r=true;
                break;
            }
        }

        for(int i=0;i<m;i++){
            if(grid[0][i]==0){
                c=true;
                break;
            }
        }

        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(grid[i][j]==0){
                    grid[i][0]=0;
                    grid[0][j]=0;
                }
            }
        }

        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(grid[i][j]==0){
                    continue;
                }
                if(grid[i][0]==0 || grid[0][j]==0){
                    grid[i][j]=0;
                }
            }
        }

        if(r){
            for(int i=0;i<n;i++){
                grid[i][0]=0;
            }
        }
        if(c){
            for(int i=0;i<m;i++){
                grid[0][i]=0;
            }
        }
    }
};