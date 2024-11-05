class Solution {
public:
    bool satisfiesConditions(vector<vector<int>>& grid) {
        //looks like i could do it in O(m*n) time complexity
        int n=grid.size();
        int m=grid[0].size();

        
        for(int i=0;i<n;i++){
            for(int j=0;j<m-1;j++){
                if(grid[i][j]==grid[i][j+1]){
                    return false;
                }
            }
        }
        for(int i=0;i<n-1;i++){
            for(int  j=0;j<m;j++){
                if(grid[i][j]!=grid[i+1][j]){
                    return false;
                }
            }
        }

        return true;
    }
};