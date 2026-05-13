1class Solution {
2public:
3
4    using ll = long long;
5
6    vector<ll> dijkstra(
7        int src,
8        vector<vector<pair<int,ll>>>& adj
9    ){
10
11        int n = adj.size();
12
13        vector<ll> dist(n, 1e18);
14
15        priority_queue<
16            pair<ll,int>,
17            vector<pair<ll,int>>,
18            greater<pair<ll,int>>
19        > pq;
20
21        dist[src] = 0;
22
23        pq.push({0, src});
24
25        while(!pq.empty()){
26
27            ll dis = pq.top().first;
28            int node = pq.top().second;
29
30            pq.pop();
31
32            for(auto it : adj[node]){
33
34                int adjNode = it.first;
35                ll edgeWeight = it.second;
36
37                if(dis + edgeWeight < dist[adjNode]){
38
39                    dist[adjNode] = dis + edgeWeight;
40
41                    pq.push({dist[adjNode], adjNode});
42                }
43            }
44        }
45
46        return dist;
47    }
48
49    vector<int> minCost(
50        int n,
51        vector<int>& prices,
52        vector<vector<int>>& roads
53    ) {
54
55        vector<vector<pair<int,ll>>> adj1(n);
56        vector<vector<pair<int,ll>>> adj2(n);
57
58        for(auto &it : roads){
59
60            int u = it[0];
61            int v = it[1];
62
63            ll cost = it[2];
64            ll taxi = it[3];
65
66            adj1[u].push_back({v, cost});
67            adj1[v].push_back({u, cost});
68
69            adj2[u].push_back({v, cost * taxi});
70            adj2[v].push_back({u, cost * taxi});
71        }
72
73        vector<vector<ll>> emptyDist(n);
74        vector<vector<ll>> loadedDist(n);
75
76        for(int i = 0; i < n; i++){
77
78            emptyDist[i] = dijkstra(i, adj1);
79
80            loadedDist[i] = dijkstra(i, adj2);
81        }
82
83        vector<int> ans(n);
84
85        for(int i = 0; i < n; i++){
86
87            ll mini = prices[i];
88
89            for(int j = 0; j < n; j++){
90
91                if(emptyDist[i][j] == 1e18 ||
92                   loadedDist[i][j] == 1e18)
93                    continue;
94
95                mini = min(
96                    mini,
97                    (ll)prices[j]
98                    + emptyDist[i][j]
99                    + loadedDist[i][j]
100                );
101            }
102
103            ans[i] = (int)mini;
104        }
105
106        return ans;
107    }
108};