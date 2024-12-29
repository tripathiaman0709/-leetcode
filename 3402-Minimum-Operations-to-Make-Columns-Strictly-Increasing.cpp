class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int sum=0;
        int maxi=0;
        for(int i=0;i<m;i++){
            maxi=grid[0][i];
            for(int j=1;j<n;j++){
                int x=max(grid[j][i],maxi+1);
                sum+=x-grid[j][i];
                maxi=max(maxi,x);
            }
        }
        return sum;
    }
};