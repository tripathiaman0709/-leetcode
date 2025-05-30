class Solution {
public:

    // void dfs(int node,vector<int>&edges,vector<bool>&vis,vector<int>&v){
    //     //writing dfs code
    //     vis[node]=true;
    //     int u=edges[node];

    //     if(u!=-1 && !vis[u]){
    //         vis[u]=true;
    //         v[u]=v[node]+1;
    //         dfs(u,edges,vis,v);
    //     }
    // }

    void bfs(int node,vector<int>&edges,vector<bool>&vis,vector<int>&v){
        queue<int>q;
        q.push(node);

        vis[node]=true;

        while(!q.empty()){
            int node=q.front();
            q.pop();

            int u=edges[node];
            if(u!=-1 && !vis[u]){
                v[u]=1+v[node];
                vis[u]=true;
                q.push(u);
            }
        }
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        //no need of adjacency vector 
        //as array itself will give the next connected vertex

        int n=edges.size();

        vector<bool>vis0(n,false);
        vector<bool>vis1(n,false);

        vector<int>v0(n,INT_MAX);
        vector<int>v1(n,INT_MAX);

        v0[node1]=0;
        v1[node2]=0;

        bfs(node1,edges,vis0,v0);
        bfs(node2,edges,vis1,v1);

        int node=-1;
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            int maxi=max(v0[i],v1[i]);

            if(mini>maxi){
                mini=maxi;
                node=i;
            }

        }
        return node;
    }
};