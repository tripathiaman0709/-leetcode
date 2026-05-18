1class Solution {
2public:
3
4    int minJumps(vector<int>& v) {
5
6        int n = v.size();
7
8        unordered_map<int, vector<int>> mpp;
9
10        for(int i = 0; i < n; i++){
11            mpp[v[i]].push_back(i);
12        }
13
14        queue<int> q;
15
16        vector<int> vis(n, 0);
17
18        q.push(0);
19
20        vis[0] = 1;
21
22        int steps = 0;
23
24        while(!q.empty()){
25
26            int sz = q.size();
27
28            while(sz--){
29
30                int ind = q.front();
31                q.pop();
32
33                if(ind == n-1){
34                    return steps;
35                }
36
37                // i-1
38                if(ind-1 >= 0 && !vis[ind-1]){
39
40                    vis[ind-1] = 1;
41
42                    q.push(ind-1);
43                }
44
45                // i+1
46                if(ind+1 < n && !vis[ind+1]){
47
48                    vis[ind+1] = 1;
49
50                    q.push(ind+1);
51                }
52
53                // same value jumps
54                for(auto it : mpp[v[ind]]){
55
56                    if(!vis[it]){
57
58                        vis[it] = 1;
59
60                        q.push(it);
61                    }
62                }
63
64                mpp[v[ind]].clear();
65            }
66
67            steps++;
68        }
69
70        return -1;
71    }
72};