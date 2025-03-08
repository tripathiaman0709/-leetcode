class Solution {
public:

    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        int z=n*n + 1;
        //frequency array
        vector<int>vis(z,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int x=grid[i][j];
                vis[x]++;
            }
        }
        vector<int>v;
        int a=-1;
        int b=-1;

        for(int i=1;i<z;i++){
            if(vis[i]==2){
                a=i;
                break;
            }
        }
        for(int i=1;i<z;i++){
            if(vis[i]==0){
                b=i;
                break;
            }
        }

        v.push_back(a);
        v.push_back(b);

        return v;
    }
};