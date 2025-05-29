class Solution {
public:

    void dfs(int curr,vector<vector<int>>&adj,int p,vector<int>&mark,int &zero,int &one){
        if(mark[curr]==0){
            zero++;
        }else{
            one++;
        }

        for(auto it:adj[curr]){
            if(it!=p){
                if(mark[curr]==0){
                    mark[it]=1;
                }else{
                    mark[it]=0;
                }
                dfs(it,adj,curr,mark,zero,one);
            }
        }
    }

    vector<vector<int>>fill(vector<vector<int>>& edges){
        vector<vector<int>>adj(edges.size()+1);
        for(auto it:edges){
            int u=it[0];
            int v=it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return adj;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n=edges1.size()+1;
        int m=edges2.size()+1;

        //creating adjacency lists

        vector<vector<int>>adj1=fill(edges1);
        vector<vector<int>>adj2=fill(edges2);


        vector<int>mark1(n,-1);
        mark1[0]=0;
        int zeroa=0;
        int onea=0;

        dfs(0,adj1,-1,mark1,zeroa,onea);

        vector<int>mark2(m,-1);
        mark2[0]=0;
        int zerob=0;
        int oneb=0;

        dfs(0,adj2,-1,mark2,zerob,oneb);


        int maxi=max(zerob,oneb);

        vector<int>ans(n);
        for(int i=0;i<n;i++){
            if(mark1[i]==0){
                ans[i]=zeroa+maxi;
            }else{
                ans[i]=onea+maxi;
            }
        }

        return ans;
    }
};