class Solution {
public:

    bool dfs(unordered_map<int,vector<int>>&adj,int u,int v,vector<bool>&vis){
        vis[u]=true;
        if(u==v){
            return true;
            //we reached destination
        }
        bool isreachable=false;
        for(auto neighbour:adj[u]){
            if(!vis[neighbour]){
                isreachable=isreachable || dfs(adj,neighbour,v,vis);
            }
        }
        return isreachable;
    }

    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        //simply dfs karo and check kr lo
        unordered_map<int,vector<int>>adj;

        for(int i=0;i<prerequisites.size();i++){
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];

            adj[u].push_back(v);
        }
        //created the adjacency list

        int n=queries.size();
        vector<bool>ans(n,false);

        for(int i=0;i<n;i++){
            int u=queries[i][0]; //source
            int v=queries[i][1]; //destination

            //agar source se start hoke destination tak pahuch gye toh dfs successfull else not
            vector<bool>vis(numCourses,false);
            ans[i]=dfs(adj,u,v,vis);
        }
        return ans;
    }
};