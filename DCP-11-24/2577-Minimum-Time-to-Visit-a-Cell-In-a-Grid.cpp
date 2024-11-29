class Solution {
public:
    #define p pair<int,pair<int,int>>
    int minimumTime(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        //storing as time, index{i,j}
        //so using priority queue
        if(grid[0][1]>1 && grid[1][0]>1){
            return -1;
        }
        int delrow[4]={-1,0,1,0};
        int delcol[4]={0,1,0,-1};
        priority_queue<p,vector<p>,greater<p>>pq;

        pq.push({0,{0,0}});
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        vector<vector<int>>result(n,vector<int>(m,0));
        while(!pq.empty()){
            int time=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();

            if(row==n-1 && col==m-1){
                return result[row][col];
            }
            if(vis[row][col]==true){
                continue;
            }

            vis[row][col]=true;

            for(int i=0;i<4;i++){
                int r=row+delrow[i];
                int c=col+delcol[i];

                if(r<0 || r>=n || c<0 || c>=m){
                    continue;
                }

                if(time+1>=grid[r][c]){
                    pq.push({time+1,{r,c}});
                    result[r][c]=time+1;
                }else if((grid[r][c]-time)%2){
                    pq.push({grid[r][c],{r,c}});
                    result[r][c]=grid[r][c];
                }else{
                    pq.push({grid[r][c]+1,{r,c}});
                    result[r][c]=grid[r][c]+1;
                }
            }
        }
        return result[n-1][m-1];

    }
};