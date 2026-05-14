1class Solution {
2public:
3
4    bool check(
5        int threshold,
6        int n,
7        vector<vector<int>>& edges,
8        int source,
9        int target,
10        int k
11    ){
12
13        vector<vector<pair<int,int>>> adj(n);
14
15        for(auto &e : edges){
16
17            int u = e[0];
18            int v = e[1];
19            int w = e[2];
20
21            int cost = (w > threshold);
22
23            adj[u].push_back({v, cost});
24            adj[v].push_back({u, cost});
25        }
26
27        vector<int> dist(n, 1e9);
28
29        priority_queue<
30            pair<int,int>,
31            vector<pair<int,int>>,
32            greater<pair<int,int>>
33        > pq;
34
35        dist[source] = 0;
36
37        pq.push({0, source});
38
39        while(!pq.empty()){
40
41            auto [dis, node] = pq.top();
42            pq.pop();
43
44            if(dis > dist[node]) continue;
45
46            for(auto &it : adj[node]){
47
48                int adjNode = it.first;
49                int edgeCost = it.second;
50
51                if(dis + edgeCost < dist[adjNode]){
52
53                    dist[adjNode] = dis + edgeCost;
54
55                    pq.push({dist[adjNode], adjNode});
56                }
57            }
58        }
59
60        return dist[target] <= k;
61    }
62
63    int minimumThreshold(
64        int n,
65        vector<vector<int>>& edges,
66        int source,
67        int target,
68        int k
69    ) {
70
71        if(source == target) return 0;
72
73        int maxi = 0;
74
75        for(auto &e : edges){
76            maxi = max(maxi, e[2]);
77        }
78
79        int low = 0;
80        int high = maxi;
81
82        int ans = -1;
83
84        while(low <= high){
85
86            int mid = low + (high - low) / 2;
87
88            if(check(mid, n, edges, source, target, k)){
89
90                ans = mid;
91
92                high = mid - 1;
93            }
94            else{
95                low = mid + 1;
96            }
97        }
98
99        return ans;
100    }
101};