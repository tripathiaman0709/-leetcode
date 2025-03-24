class Solution {
public:

    int intersect(vector<int>&a,vector<int>&b){
        int n=a.size();
        int m=b.size();

        // set<int>st;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         if(a[i]==b[j]){
        //             st.insert(a[i]);
        //         }
        //     }
        // }
        // //finds all common elements
        // return st.size();
        // //set return all unique out of those common elements

        // set<int>sa;
        // set<int>s;
        // for(auto it:a){
        //     sa.insert(it);
        // }

        // for(int i=0;i<m;i++){
        //     if(sa.count(b[i])){
        //         s.insert(b[i]);
        //     }
        // }
        // return s.size();
        set<int>s;
        sort(a.begin(),a.end());
        for(int i=0;i<m;i++){
            if(binary_search(a.begin(),a.end(),b[i])){
                s.insert(b[i]);
            }
        }
        return s.size();
    }

    void dfs(vector<bool>&vis,vector<vector<int>>&adj,int i){
        vis[i]=true;
        for(auto it:adj[i]){
            if(!vis[it]){
                dfs(vis,adj,it);
            }
        }
    }

    int numberOfComponents(vector<vector<int>>& p, int k) {
        //easy hai 
        //bas ajeeb tarah se likha hai

        //intersect function banake graph form kro
        //then number of connected compo nikaalna toh easy hi hai dfs laga lo
        
        int n=p.size();
        int m=p[0].size();
        vector<vector<int>>adj(n);

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(i==j){
                    continue;
                }
                if(intersect(p[i],p[j])>=k){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<bool>vis(n,false);
        int count=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(vis,adj,i);
                count++;
            }
        }
        return count;
    }
};