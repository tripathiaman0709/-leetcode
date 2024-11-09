class Solution {
public:

    int count=0;
    void dfs(int source,int parent,vector<vector<pair<int,int>>>&adj){
        for(auto it:adj[source]){
            int v=it.first;
            int check=it.second;

            if(v!=parent){
                if(check==1){
                    count++;
                }
                dfs(v,source,adj);
            }
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        int x=connections.size();
        vector<vector<pair<int,int>>>adj(x+1);
        for(int i=0;i<x;i++){
            int from=connections[i][0];
            int to  =connections[i][1];

            adj[from].push_back({to,1});//asli
            adj[to].push_back({from,0});//nkli
        }
        dfs(0,-1,adj);

        return count;
    }
};