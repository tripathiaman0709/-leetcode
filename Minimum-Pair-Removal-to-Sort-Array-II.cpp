1class Solution {
2public:
3    typedef long long ll;
4
5    int minimumPairRemoval(vector<int>& nums) {
6        int n = nums.size();
7        if (n <= 1) return 0;
8
9        vector<ll> a(nums.begin(), nums.end());
10        vector<int> prv(n), nxt(n);
11        vector<bool> removed(n, false);
12
13        for (int i = 0; i < n; i++) {
14            prv[i] = i - 1;
15            nxt[i] = i + 1;
16        }
17        nxt[n - 1] = -1;
18
19        int bad = 0;
20        for (int i = 0; i + 1 < n; i++) {
21            if (a[i] > a[i + 1]) bad++;
22        }
23
24        priority_queue<pair<ll,int>,
25            vector<pair<ll,int>>,
26            greater<pair<ll,int>>> pq;
27
28        for (int i = 0; i + 1 < n; i++) {
29            pq.push({a[i] + a[i + 1], i});
30        }
31
32        int ops = 0;
33
34        while (bad > 0) {
35            auto [sum, i] = pq.top();
36            pq.pop();
37
38            if (removed[i] || nxt[i] == -1) continue;
39            int j = nxt[i];
40            if (removed[j] || a[i] + a[j] != sum) continue;
41
42            int L = prv[i];
43            int R = nxt[j];
44
45            // remove old violations
46            if (L != -1 && a[L] > a[i]) bad--;
47            if (a[i] > a[j]) bad--;
48            if (R != -1 && a[j] > a[R]) bad--;
49
50            // merge
51            a[i] = sum;
52            removed[j] = true;
53            nxt[i] = R;
54            if (R != -1) prv[R] = i;
55
56            // add new violations
57            if (L != -1 && a[L] > a[i]) bad++;
58            if (R != -1 && a[i] > a[R]) bad++;
59
60            // push new adjacent pairs
61            if (L != -1)
62                pq.push({a[L] + a[i], L});
63            if (R != -1)
64                pq.push({a[i] + a[R], i});
65
66            ops++;
67        }
68
69        return ops;
70    }
71};