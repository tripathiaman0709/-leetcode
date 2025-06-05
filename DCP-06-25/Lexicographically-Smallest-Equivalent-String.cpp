class Solution {
public:

    char dfs(vector<vector<char>>&adj, char curr, vector<int>&vis){
        //marking current character as visited

        vis[curr-'a']=1;
        char minchar=curr;

        for(auto neighbour:adj[curr]){
            if(vis[neighbour-'a']==1){
                continue;
            }
            minchar=min(minchar,dfs(adj,neighbour,vis));
        }

        return minchar;
    }

    string smallestEquivalentString(string s1, string s2, string s) {
        int n=s1.size();

        int m=s.size();

        //firstly making an adjacency list
        //as many elements can be connected to one element so making a graph

        vector<vector<char>>adj(150);

        for(int i=0;i<n;i++){
            char u=s1[i];
            char v=s2[i];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        string ans="";

        for(int i=0;i<m;i++){
            char ch=s[i];
            vector<int>vis(26,0);
            ans+=dfs(adj,ch,vis);
        }
        return ans;
    }
};