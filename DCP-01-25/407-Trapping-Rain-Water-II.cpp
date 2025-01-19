class Solution {
public:

    typedef pair<int,pair<int,int>> pp;

    int trapRainWater(vector<vector<int>>& hmp) {
        //using priority queue approach
        //min heap
        int n=hmp.size();
        int m=hmp[0].size();

        vector<vector<int>>dir={{-1,0},{0,1},{1,0},{0,-1}};

        //also using visited array
        vector<vector<bool>>vis(n,vector<bool>(m,false));

        priority_queue<pp,vector<pp>,greater<>>pq;
        //pushing all the boundary elements
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(j==0 || j==m-1){
                    pq.push({hmp[i][j],{i,j}});
                    vis[i][j]=true;
                }                
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(j==0 || j==n-1){
                    pq.push({hmp[j][i],{j,i}});
                    vis[j][i]=true;
                }
            }
        }
        int water=0;
        while(!pq.empty()){
            auto x=pq.top();
            pq.pop();

            int height=x.first;
            int i=x.second.first;
            int j=x.second.second;

            for(int k=0;k<=3;k++){
                int i_=i+dir[k][0];
                int j_=j+dir[k][1];

                if(i_>=0 && j_>=0 && i_<n && j_<m && vis[i_][j_]==false){
                    water+=max(height-hmp[i_][j_],0);

                    pq.push({max(height,hmp[i_][j_]),{i_,j_}});
                    vis[i_][j_]=true;
                }
            }
        }

        return water;  

    }
};