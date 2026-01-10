1class Solution {
2public:
3
4    bool check(string &top,string &left,string &right,string &bottom){
5        return (top[0]==left[0] && top[3]==right[0] && bottom[0]==left[3] && bottom[3]==right[3]);
6    }
7
8    vector<vector<string>> wordSquares(vector<string>& v) {
9        int n=v.size();
10        //as only 4 words are given
11        //so applying all possible possiblities of how the words could be arranged
12
13        vector<vector<string>> ans;
14
15                for (int i = 0; i < n; i++) {          // top
16                    for (int j = 0; j < n; j++) {      // left
17                        if (j == i) continue;
18                        if (v[i][0] != v[j][0]) continue;
19
20                        for (int k = 0; k < n; k++) {  // right
21                            if (k == i || k == j) continue;
22                            if (v[i][3] != v[k][0]) continue;
23
24                            for (int l = 0; l < n; l++) { // bottom
25                                if (l == i || l == j || l == k) continue;
26
27                                if (check(v[i], v[j], v[k], v[l])) {
28                                    ans.push_back({
29                                        v[i],
30                                        v[j],
31                                        v[k],
32                                        v[l]
33                                    });
34                                }
35                            }
36                        }
37                    }
38                }
39                sort(ans.begin(),ans.end());
40                return ans;
41    }
42};