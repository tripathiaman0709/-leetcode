class Solution {
public:
    int n;
    pair<int,int>fun(int n,int val){
        int rt=(val-1)/n;
        int rb=(n-1)-rt;

        int col=(val-1)%n;

        if((n%2==rb%2)){
            col=(n-1)-col;
        }     

        return make_pair(rb,col); 
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        //remember whenever we talk about minimum steps 
        //think about bfs or dijkstra

        //the major chaalenge in this question is to get the coordinates of the board 
        //as it changes from right to left and left to right

        n=board.size();
        int count=0;
        vector<vector<int>>vis(n,vector<int>(n,0));

        queue<int>q;
        q.push(1);
        vis[n-1][0]=1;

        while(!q.empty()){
            int sz=q.size();

            while(sz--){
                int val=q.front();
                q.pop();

                if(val==n*n){
                    return count;
                }

                for(int i=1;i<=6;i++){
                    int newval=val+i;

                    if(newval>n*n){
                        break;
                    }

                    pair<int,int>cd=fun(n,newval);

                    int r=cd.first;
                    int c=cd.second;

                    if(vis[r][c]==1){
                        continue;
                    }
                    vis[r][c]=1;
                    if(board[r][c]==-1){
                        q.push(newval);
                    }else{
                        q.push(board[r][c]);
                    }
                }                
            }
            count++;
        }
        return -1;           
    }
};