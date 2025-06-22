class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& vec, vector<int>& time) {
        //simply topological osrt using kahns algorithm

        vector<vector<int>>adj(n+1);
        vector<int>indegree(n+1);

        for(int i=0;i<vec.size();i++){
            int u=vec[i][0]-1;
            int v=vec[i][1]-1;

            adj[u].push_back(v);
            indegree[v]++;
        }
        vector<int>maxtime(n,0);
        queue<int>q;

        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
                maxtime[i]=time[i];
            }
        }

        while(!q.empty()){
            int u=q.front();
            q.pop();

            for(auto it:adj[u]){
                indegree[it]--;

                maxtime[it]=max(maxtime[it],maxtime[u]+time[it]);

                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        return *max_element(maxtime.begin(),maxtime.end());
    }
};