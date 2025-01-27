class Solution {
public:

    // bool dfs(unordered_map<int,vector<int>>&adj,int u,int v,vector<bool>&vis){
    //     vis[u]=true;
    //     if(u==v){
    //         return true;
    //         //we reached destination
    //     }
    //     bool isreachable=false;
    //     for(auto neighbour:adj[u]){
    //         if(!vis[neighbour]){
    //             isreachable=isreachable || dfs(adj,neighbour,v,vis);
    //         }
    //     }
    //     return isreachable;
    // }

    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        // //simply dfs karo and check kr lo
        // unordered_map<int,vector<int>>adj;

        // for(int i=0;i<prerequisites.size();i++){
        //     int u=prerequisites[i][0];
        //     int v=prerequisites[i][1];

        //     adj[u].push_back(v);
        // }
        // //created the adjacency list

        // int n=queries.size();
        // vector<bool>ans(n,false);

        // for(int i=0;i<n;i++){
        //     int u=queries[i][0]; //source
        //     int v=queries[i][1]; //destination

        //     //agar source se start hoke destination tak pahuch gye toh dfs successfull else not
        //     vector<bool>vis(numCourses,false);
        //     ans[i]=dfs(adj,u,v,vis);
        // }
        // return ans;


        //now simply doing topological sorting
        unordered_map<int,vector<int>>adj;
        vector<int>inorder(numCourses,0);
        for(int i=0;i<prerequisites.size();i++){
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            adj[u].push_back(v);
            inorder[v]++;
        }
        int n=queries.size();
        vector<bool>ans(n,false);
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(inorder[i]==0){
                q.push(i);
            }
        }
        unordered_map<int,unordered_set<int>>mpp;
        while(!q.empty()){
            auto node=q.front();
            q.pop();

            for(auto neighbour:adj[node]){
                mpp[neighbour].insert(node);
                for(auto it:mpp[node]){
                    mpp[neighbour].insert(it);
                }
                inorder[neighbour]--;
                if(inorder[neighbour]==0){
                    q.push(neighbour);
                }
            }            
        }
        for(int i=0;i<n;i++){
            int src =queries[i][0];
            int dest=queries[i][1];

            if(mpp[dest].count(src)>0){
                ans[i]=true;
            }
        }

        return ans;
    }
};