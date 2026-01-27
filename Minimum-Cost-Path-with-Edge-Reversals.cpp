1class Solution {
2public:
3    int minCost(int n, vector<vector<int>>& edge) {
4        //making adjacency list
5
6        vector<vector<pair<int,int>>>adj(n+1);
7        for(int i=0;i<edge.size();i++){
8            int u=edge[i][0];
9            int v=edge[i][1];
10            int w=edge[i][2];
11
12            adj[u].push_back({v,w});
13            adj[v].push_back({u,2*w});
14        }
15
16        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
17
18        vector<int>dis(n+1,100000001);
19        dis[0]=0;
20        pq.push({0,0});
21        while(!pq.empty()){
22            auto it=pq.top();
23            pq.pop();
24
25            int u=it.second;
26            int d=it.first;
27
28            if(d>dis[u]) continue;
29
30            for(auto x:adj[u]){
31                int v=x.first;
32                int newd=x.second;
33
34                if(dis[v]>dis[u]+newd){
35                    dis[v]=dis[u]+newd;
36                    pq.push({dis[v],v});
37                }
38            }
39        }
40        if(dis[n-1]==100000001){
41            return -1;
42        }
43        return dis[n-1];
44    }
45};