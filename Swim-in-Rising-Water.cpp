class Solution {
public:
    #define P pair<int,pair<int,int>>

    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();

        //using simple dijkstra 
        //which means use of priority queue

        priority_queue<P,vector<P>,greater<P>>pq;
        vector<vector<int>>vis(n+1,vector<int>(n+1,0));//initially none of the points are visited

        vis[0][0]=1;
        pq.push({grid[0][0],{0,0}});
        int ans=0;

        int r[4]={-1,0,1,0};
        int c[4]={0,1,0,-1};

        while(!pq.empty()){
            int elevation=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();

            ans=max(ans,elevation);

            if(row==n-1 && col==n-1){
                return ans;
            }

            for(int i=0;i<4;i++){
                int nrow=row+r[i];
                int ncol=col+c[i];

                if(nrow<n && ncol<n && nrow>=0 && ncol>=0 && !vis[nrow][ncol]){
                    vis[nrow][ncol]=1;
                    pq.push({grid[nrow][ncol],{nrow,ncol}});
                }
            }
        }

        return ans;

    }
};