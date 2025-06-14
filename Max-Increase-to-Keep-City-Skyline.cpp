class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        vector<vector<int>>copy=grid;
        int n=grid.size();
        int m=grid[0].size();

        vector<int>row(n);
        vector<int>col(m);

        for(int i=0;i<n;i++){
            int maxi=0;
            for(int j=0;j<m;j++){
                maxi=max(maxi,grid[i][j]);
            }

            row[i]=maxi;
        }

        for(int i=0;i<m;i++){
            int maxi=0;
            for(int j=0;j<n;j++){
                maxi=max(maxi,grid[j][i]);
            }

            col[i]=maxi;
        }
        int sum=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]>=min(row[i],col[j])){
                    continue;
                }
                sum+=min(row[i],col[j])-grid[i][j];
            }
        }

        return sum;




    }
};