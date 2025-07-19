class Solution {
public:

    void dfs(int node,vector<vector<int>>&adj,vector<bool>&vis){
        vis[node]=true;

        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,adj,vis);
            }
        }

    }

    int fun(int n,vector<vector<int>>& edges, int mid){
        vector<vector<int>>adj(n);

        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];

            if(wt<=mid){
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }

        vector<bool>vis(n,false);
        int comp=0;

        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,adj,vis);
                comp++;
            }
        }
        return comp;
    }

    int minCost(int n, vector<vector<int>>& edges, int k) {
        int low=0;
        int high=1e6;
        int ans=0;

        while(low<=high){
            int mid=low+(high-low)/2;
            int comp=fun(n,edges,mid);

            if(comp<=k){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};