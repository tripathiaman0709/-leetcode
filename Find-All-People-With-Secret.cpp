1class Solution {
2public:
3    vector<int> findAllPeople(int n, vector<vector<int>>& meet, int fp) {
4
5        // Group meetings in increasing order of time
6        map<int, vector<pair<int,int>>> timeMeetings;
7        for (auto &m : meet) {
8            int x = m[0], y = m[1], t = m[2];
9            timeMeetings[t].push_back({x, y});
10        }
11
12        // ks -> knows secret
13        vector<bool> ks(n, false);
14        ks[0] = true;
15        ks[fp] = true;
16
17        for (auto &entry : timeMeetings) {
18            int t = entry.first;
19            auto &meetings = entry.second;
20
21            // Build adjacency list for time t only
22            unordered_map<int, vector<int>> meetList;
23            for (auto &p : meetings) {
24                int x = p.first, y = p.second;
25                meetList[x].push_back(y);
26                meetList[y].push_back(x);
27            }
28
29            // Find starting points
30            unordered_set<int> start;
31            for (auto &p : meetings) {
32                int x = p.first, y = p.second;
33                if (ks[x]) start.insert(x);
34                if (ks[y]) start.insert(y);
35            }
36
37            // BFS
38            queue<int> q;
39            for (int s : start) q.push(s);
40
41            while (!q.empty()) {
42                int person = q.front();
43                q.pop();
44
45                for (int nextPerson : meetList[person]) {
46                    if (!ks[nextPerson]) {
47                        ks[nextPerson] = true;
48                        q.push(nextPerson);
49                    }
50                }
51            }
52        }
53
54        vector<int> res;
55        for (int i = 0; i < n; i++) {
56            if (ks[i]) res.push_back(i);
57        }
58        return res;
59    }
60};