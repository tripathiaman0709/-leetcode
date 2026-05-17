1class Solution {
2public:
3
4    int minGenerations(vector<vector<int>>& v, vector<int>& k) {
5
6        int count = 0;
7
8        for(auto it : v){
9            if(it == k) return 0;
10        }
11
12        set<vector<int>> st;
13
14        for(auto it : v){
15            st.insert(it);
16        }
17
18        while(true){
19
20            vector<vector<int>> all(st.begin(), st.end());
21
22            vector<vector<int>> curr;
23
24            for(int i = 0; i < all.size(); i++){
25
26                int x1 = all[i][0];
27                int y1 = all[i][1];
28                int z1 = all[i][2];
29
30                for(int j = i + 1; j < all.size(); j++){
31
32                    int x2 = all[j][0];
33                    int y2 = all[j][1];
34                    int z2 = all[j][2];
35
36                    int x3 = (x1 + x2) / 2;
37                    int y3 = (y1 + y2) / 2;
38                    int z3 = (z1 + z2) / 2;
39
40                    vector<int> add = {x3, y3, z3};
41
42                    if(add == k){
43                        return count + 1;
44                    }
45
46                    if(st.count(add) == 0){
47
48                        curr.push_back(add);
49
50                        st.insert(add);
51                    }
52                }
53            }
54
55            if(curr.size() == 0){
56                return -1;
57            }
58
59            count++;
60        }
61
62        return -1;
63    }
64};