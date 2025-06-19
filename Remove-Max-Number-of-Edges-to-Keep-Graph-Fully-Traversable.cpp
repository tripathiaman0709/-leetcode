class DisjointSet {
    vector<int> rank, parent, size;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {

        DisjointSet ds1(n+1),ds2(n+1);
        int res=0;
        for(auto it:edges){
            if(it[0]==3){
                if(ds1.findUPar(it[1])!=ds2.findUPar(it[2])){
                    ds1.unionBySize(it[1],it[2]);
                    ds2.unionBySize(it[1],it[2]);
                }
                else{
                    res++;
                }
  
            }
            
        }
        for(auto it:edges){
            if(it[0]==1){
                if(ds1.findUPar(it[1])!=ds1.findUPar(it[2])){
                    ds1.unionBySize(it[1],it[2]);
                }
                else{
                     res++;
                }
            }
        }
         for(auto it:edges){
            if(it[0]==2){
                if(ds2.findUPar(it[1])!=ds2.findUPar(it[2])){
                    ds2.unionBySize(it[1],it[2]);
                }
                else{
                     res++;
                }
            }
        }
        set<int>sett1,sett2;
        for(int i=1;i<=n;i++){
            sett1.insert(ds1.findUPar(i));
            sett2.insert(ds2.findUPar(i));
        }
        if(sett1.size()!=1 || sett2.size()!=1)return -1;
        return res;
    }
};