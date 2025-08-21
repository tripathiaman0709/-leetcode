class Solution {
public:
    int numSubmat(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        int startrow=0;
        int endrow=0;
        int total=0;

        while(startrow<n){
            int consecutiveones=0;

            vector<int>temp(m,1);
            
            for(int i=0;i<m;i++){
                for(int j=startrow;j<=endrow;j++){
                    if(grid[j][i]!=1){
                        temp[i]=0;
                        break;
                    }
                }
            }

            for(int i=0;i<m;i++){
                if(temp[i]==1){
                    consecutiveones++;
                }else{
                    consecutiveones=0;
                }
                total+=consecutiveones;
            }

            endrow++;

            if(endrow>=n){
                startrow++;
                endrow=startrow;
            }
        }

        return total;
    }
};