1class Solution {
2public:
3    int countCoveredBuildings(int n, vector<vector<int>>& v) {
4        // vector<int>x;
5        // vector<int>y;
6
7        // for(int i=0;i<v.size();i++){
8        //     x.push_back(v[i][0]);
9        //     y.push_back(v[i][1]);
10        // }
11        // sort(x.begin(),x.end());
12        // sort(y.begin(),y.end());
13        // int count=0;
14        // for(int i=0;i<v.size();i++){
15        //     int x1=v[i][0];
16        //     int y1=v[i][1];
17
18        //     int xleft= lower_bound(x.begin(),x.end(),x1)-x.begin()-1;
19        //     int xright=upper_bound(x.begin(),x.end(),x1)-x.begin();
20
21        //     int yleft= lower_bound(y.begin(),y.end(),y1)-y.begin()-1;
22        //     int yright=upper_bound(y.begin(),y.end(),y1)-y.begin();
23
24        //     if(xleft<0 || yleft<0 || xright>v.size()-1 || yright>v.size()-1){
25        //         continue;
26        //     }
27
28        //     if(x[xleft]<x1 && y[yleft]<y1 && x[xright]>x1 && y[yright]>y1){
29        //         count++;
30        //     }
31        // }
32        // return count;
33
34
35
36        unordered_map<int, set<int>> mx;
37        unordered_map<int, set<int>> my;
38
39        int N = v.size();
40
41        for (int i = 0; i < N; i++) {
42            int x1 = v[i][0];
43            int y1 = v[i][1];
44            mx[x1].insert(y1);
45            my[y1].insert(x1);
46        }
47
48        int count = 0;
49
50        for (int i = 0; i < N; i++) {
51            int x1 = v[i][0];
52            int y1 = v[i][1];
53
54            bool goodY = false;
55
56            auto &setY = mx[x1];
57            if (!setY.empty()) {
58                bool small = false;
59                auto it_small = setY.lower_bound(y1);
60                if (it_small != setY.begin()) small = true;
61
62                bool large = false;
63                auto it_large = setY.upper_bound(y1);
64                if (it_large != setY.end()) large = true;
65
66                if (small && large) goodY = true;
67            }
68
69            if (!goodY) continue;
70
71            bool goodX = false;
72
73            auto &setX = my[y1];
74            if (!setX.empty()) {
75                bool small = false;
76                auto it_small = setX.lower_bound(x1);
77                if (it_small != setX.begin()) small = true;
78
79                bool large = false;
80                auto it_large = setX.upper_bound(x1);
81                if (it_large != setX.end()) large = true;
82
83                if (small && large) goodX = true;
84            }
85
86            if (goodX && goodY) count++;
87        }
88
89        return count;
90    }
91};