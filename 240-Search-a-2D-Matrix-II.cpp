class Solution {
public:
    bool searchMatrix(vector<vector<int>>& grid, int k) {
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==k){
                    return true;
                }
            }
        }
        return false;
        
    }
};