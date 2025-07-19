class Solution {
public:

    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};

    long long dfs(int r,int c,vector<vector<int>>& grid,vector<vector<int>>& vis){
        vis[r][c]=1;
        long long sum=grid[r][c];
        int n=grid.size();
        int m=grid[0].size();

        for(int i=0;i<4;i++){
            int nr=r+dx[i];
            int nc=c+dy[i];
            
            if(nr<n && nr>=0 && nc>=0 && nc<m && grid[nr][nc]!=0 && vis[nr][nc]==0){
                sum+=dfs(nr,nc,grid,vis);
            }
        }

        return sum;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        //i think a simple dfs traversal with visited track will do the job
        int n=grid.size();
        int m=grid[0].size();

        int count=0;

        vector<vector<int>>vis(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                //not visted the cell yet
                //it is a land cell
                if(vis[i][j]==0 && grid[i][j]!=0){
                    if(dfs(i,j,grid,vis)%k==0 && dfs(i,j,grid,vis)!=0){
                        count++;
                    }
                }
            }
        }       
        return count; 
    }
};