1class Solution {
2public:
3    int n;
4    int t[100001][3];
5    
6    //upper_bound of endTime
7    int binarySearch(vector<vector<int>>& events, int endTime) {
8        int l = 0;
9        int r = n-1;
10        int result = n;
11
12        while(l <= r) {
13            int mid = l + (r-l)/2;
14
15            if(events[mid][0] > endTime) {
16                result = mid;
17                r = mid-1;
18            } else {
19                l = mid+1;
20            }
21        }
22
23        return result;
24    }
25
26    int solve(vector<vector<int>>& events, int i, int count) {
27        if(count == 2 || i >= n) {
28            return 0;
29        }
30
31        if(t[i][count] != -1) {
32            return t[i][count];
33        }
34
35        int nextValidEventIndex = binarySearch(events, events[i][1]);
36        int take = events[i][2] + solve(events, nextValidEventIndex, count+1);
37
38        int not_take = solve(events, i+1, count);
39
40        return t[i][count] = max(take, not_take);
41    }
42
43    int maxTwoEvents(vector<vector<int>>& events) {
44        n = events.size();
45        sort(begin(events), end(events));
46        memset(t, -1, sizeof(t));
47
48        int count = 0;
49        return solve(events, 0, count);
50    }
51};