class Solution {
public:
    int minTimeToReach(vector<vector<int>>& grid) {
        //hmm priority queue lagana hoga
        //as greedily toh solve nhi ho paayega

        int n=grid.size();
        int m=grid[0].size();

        //chlo dijkstra's algorithm lagaya jaaye
        //initialising a minimum priority queue

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;

        pq.push({0,{0,0}});
        //distance , coordinates -> i,j

        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};

        vector<vector<int>>finalgrid(n,vector<int>(m,INT_MAX));
        finalgrid[0][0]=0;
        //source

        while(!pq.empty()){
            int cost=pq.top().first;
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            pq.pop();

            if(x==n-1 && y==m-1){
                return cost;
            }

            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                    int wait=grid[nx][ny]-cost;
                    int newcost=0;
                    if(wait>0){
                        newcost=wait+cost+1;
                    }                    
                    else{
                       newcost=cost+1; 
                    }
                    if (newcost < finalgrid[nx][ny]) {
                        finalgrid[nx][ny] = newcost;
                        pq.push({newcost, {nx, ny}});
                    }
                }
            }
        }
        return -1;
    }
};