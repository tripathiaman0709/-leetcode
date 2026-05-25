1class Solution {
2public:
3    bool canReach(string s, int mini, int maxi) {
4
5        int n = s.size();
6
7        vector<bool> vis(n, false);
8
9        queue<int> q;
10
11        q.push(0);
12        vis[0] = true;
13
14        int farthest = 0;
15
16        while(!q.empty()) {
17
18            int cur = q.front();
19            q.pop();
20
21            if(cur == n - 1) {
22                return true;
23            }
24
25            int start = max(cur + mini, farthest + 1);
26            int end = min(cur + maxi, n - 1);
27
28            for(int i = start; i <= end; i++) {
29
30                if(s[i] == '0' && !vis[i]) {
31                    vis[i] = true;
32                    q.push(i);
33                }
34            }
35
36            farthest = end;
37        }
38
39        return false;
40    }
41};