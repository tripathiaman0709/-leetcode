class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n=grid.size();

        for(int i=0;i<n;i++){
            int row=i;
            int col=0;
            vector<int>temp;
            while(row<n && col<n){
                temp.push_back(grid[row][col]);
                row++;
                col++;
            }
            int nrow=i;
            int ncol=0;
            int x=0;
            sort(temp.rbegin(),temp.rend());
            while(nrow<n && ncol<n){
                grid[nrow][ncol]=temp[x];
                x++;
                nrow++;
                ncol++;
            }
        }

        for(int i=1;i<n;i++){
            int row=0;
            int col=i;
            vector<int>temp;
            while(row<n && col<n){
                temp.push_back(grid[row][col]);
                row++;
                col++;
            }
            int nrow=0;
            int ncol=i;
            int x=0;
            sort(temp.begin(),temp.end());
            while(nrow<n && ncol<n){
                grid[nrow][ncol]=temp[x];
                x++;
                nrow++;
                ncol++;
            }
        }

        return grid;
    }
};