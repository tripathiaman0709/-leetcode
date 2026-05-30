1class Fenwick {
2    int n;
3    vector<int> bit;
4
5public:
6    Fenwick(int n = 0) : n(n), bit(n + 1, 0) {}
7
8    void add(int idx, int val) {
9        for (; idx <= n; idx += idx & -idx) {
10            bit[idx] += val;
11        }
12    }
13
14    int sum(int idx) const {
15        int res = 0;
16        for (; idx > 0; idx -= idx & -idx) {
17            res += bit[idx];
18        }
19        return res;
20    }
21
22    int kth(int k) const {
23        int idx = 0;
24        int step = 1;
25        while ((step << 1) <= n) step <<= 1;
26
27        for (int d = step; d > 0; d >>= 1) {
28            int next = idx + d;
29            if (next <= n && bit[next] < k) {
30                idx = next;
31                k -= bit[next];
32            }
33        }
34        return idx + 1;
35    }
36};
37
38class SegTree {
39    int n;
40    vector<int> tree;
41
42    void update(int node, int l, int r, int pos, int val) {
43        if (l == r) {
44            tree[node] = val;
45            return;
46        }
47        int mid = (l + r) >> 1;
48        if (pos <= mid) update(node << 1, l, mid, pos, val);
49        else update(node << 1 | 1, mid + 1, r, pos, val);
50        tree[node] = max(tree[node << 1], tree[node << 1 | 1]);
51    }
52
53    int query(int node, int l, int r, int ql, int qr) const {
54        if (ql > r || qr < l) return 0;
55        if (ql <= l && r <= qr) return tree[node];
56        int mid = (l + r) >> 1;
57        return max(query(node << 1, l, mid, ql, qr),
58                   query(node << 1 | 1, mid + 1, r, ql, qr));
59    }
60
61public:
62    SegTree(int n = 0) : n(n), tree(4 * max(1, n), 0) {}
63
64    void setVal(int pos, int val) {
65        if (n == 0) return;
66        update(1, 0, n - 1, pos, val);
67    }
68
69    int getMax(int l, int r) const {
70        if (n == 0 || l > r) return 0;
71        return query(1, 0, n - 1, l, r);
72    }
73};
74
75class Solution {
76public:
77    vector<bool> getResults(vector<vector<int>>& queries) {
78        int mx = 0;
79        for (auto &q : queries) {
80            mx = max(mx, q[1]);
81        }
82
83        int fenwickSize = mx + 2;
84        Fenwick fw(fenwickSize);
85
86        SegTree st(mx + 1);
87
88        fw.add(1, 1);
89
90        vector<bool> ans;
91        ans.reserve(queries.size());
92
93        for (auto &q : queries) {
94            int type = q[0];
95            int x = q[1];
96
97            if (type == 1) {
98                int leftCount = fw.sum(x);
99                int leftPos = fw.kth(leftCount) - 1;
100
101                int occupiedUpToX = fw.sum(x + 1);
102                int totalOccupied = fw.sum(fenwickSize);
103                int rightPos = -1;
104                if (occupiedUpToX < totalOccupied) {
105                    rightPos = fw.kth(occupiedUpToX + 1) - 1;
106                }
107
108                st.setVal(x, x - leftPos);
109
110                if (rightPos != -1) st.setVal(rightPos, rightPos - x);
111
112                fw.add(x + 1, 1);
113            } else {
114                int sz = q[2];
115
116                int leftCount = fw.sum(x);
117                int leftPos = fw.kth(leftCount) - 1;
118
119                int bestPrefix = st.getMax(0, x);
120
121                ans.push_back((x - leftPos >= sz) || (bestPrefix >= sz));
122            }
123        }
124
125        return ans;
126    }
127};