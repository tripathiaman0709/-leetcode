1class DSU {
2public:
3    vector<int> parent, size;
4
5    DSU(int n) {
6        parent.resize(n);
7        size.resize(n, 1);
8        for(int i = 0; i < n; i++) parent[i] = i;
9    }
10
11    int findUPar(int node) {
12        if(node == parent[node]) return node;
13        return parent[node] = findUPar(parent[node]); // path compression
14    }
15
16    void unionBySize(int u, int v) {
17        int pu = findUPar(u);
18        int pv = findUPar(v);
19
20        if(pu == pv) return;
21
22        if(size[pu] < size[pv]) {
23            parent[pu] = pv;
24            size[pv] += size[pu];
25        } else {
26            parent[pv] = pu;
27            size[pu] += size[pv];
28        }
29    }
30};
31
32class Solution {
33public:
34    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
35        int n = source.size();
36        DSU dsu(n);
37
38        // Step 1: Build components
39        for(auto &it : allowedSwaps) {
40            dsu.unionBySize(it[0], it[1]);
41        }
42
43        // Step 2: Group indices by parent
44        unordered_map<int, vector<int>> components;
45        for(int i = 0; i < n; i++) {
46            int parent = dsu.findUPar(i);
47            components[parent].push_back(i);
48        }
49
50        int ans = 0;
51
52        // Step 3: Process each component
53        for(auto &comp : components) {
54            vector<int> indices = comp.second;
55
56            unordered_map<int, int> freq;
57
58            // Count source values
59            for(int idx : indices) {
60                freq[source[idx]]++;
61            }
62
63            // Match with target
64            for(int idx : indices) {
65                if(freq[target[idx]] > 0) {
66                    freq[target[idx]]--;
67                } else {
68                    ans++; // mismatch
69                }
70            }
71        }
72
73        return ans;
74    }
75};