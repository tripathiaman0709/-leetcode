1class Solution {
2public:
3    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
4        int moveX[4] = {0, 1, 0, -1};
5        int moveY[4] = {1, 0, -1, 0};
6        set<pair<int, int>> st;
7        for (auto it : obstacles) {
8            st.insert({it[0], it[1]});
9        }
10        int x_start = 0, y_start = 0, direction = 0;
11        int maxi = 0;
12        for (auto it : commands) {
13            // turn left
14            if (it == -2) {
15                direction = (direction + 3) % 4;
16            }
17            // turn right
18            else if (it == -1) {
19                direction = (direction + 1) % 4;
20            }
21            else {
22                int moves = it;
23                while (moves > 0) {
24                    int x_new = x_start + moveX[direction];
25                    int y_new = y_start + moveY[direction];
26
27                    if (st.find({x_new, y_new}) == st.end()) {
28                        //nhi mila
29                        x_start = x_new;
30                        y_start = y_new;
31                        moves--;
32                        maxi = max(maxi, ((x_start*x_start)+(y_start*y_start)));
33                    }
34                    else{
35                        //obstacle mil gaya
36                        break;
37                    }
38                }
39            }
40        }
41        return maxi;
42    }
43};