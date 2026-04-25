1class Solution {
2public:
3    typedef long long ll;
4
5    ll get1D(int side, int x, int y) {
6        if(y == 0) return x;
7
8        if(x == side) return side + y;
9
10        if(y == side) return 3LL * side - x;
11
12        return 4LL * side - y;
13    }
14
15    bool check(vector<ll>& doubled, int n, int k, int side, int mid) {
16        ll perimeter = 4LL * side;
17
18        for(int i = 0; i < n; i++) { //O(n)
19            int count = 1; //Picked one point
20            int idx   = i;
21
22            ll lastPos = doubled[idx];
23
24            for(int j = 2; j <= k; j++) { //O(k * log(n))
25                ll target = lastPos + mid;
26
27                auto it = lower_bound(begin(doubled) + idx + 1, begin(doubled) + i + n, target);
28
29                if(it == begin(doubled) + i + n) break;
30
31                idx = it - begin(doubled);
32                lastPos = doubled[idx];
33                count++;
34            }
35
36            if(count == k && (doubled[i] + perimeter - lastPos >= mid)) {
37                return true;
38            }
39        }
40
41        return false;
42    }
43
44    int maxDistance(int side, vector<vector<int>>& points, int k) {
45        ll perimeter = 4LL * side;
46        int n = points.size();
47
48        vector<ll> positions(n);
49
50        for(int i = 0; i < n; i++) {
51            positions[i] = get1D(side, points[i][0], points[i][1]);
52        }
53
54        sort(begin(positions), end(positions));
55
56        //double the positions array to easily handle round wrap
57        vector<ll> doubled(2*n);
58        for(int i = 0; i < n; i++) {
59            doubled[i]   = positions[i];
60            doubled[i+n] = positions[i] + perimeter;
61        }
62
63        int l = 0;
64        int r = 2*side;
65
66        int result = 0;
67
68        //log(side) * n * klog(n)
69        while(l <= r) {
70            int mid = l + (r-l)/2;
71
72            if(check(doubled, n, k, side, mid)) {
73                result = mid;
74                l = mid+1;
75            } else {
76                r = mid-1;
77            }
78        }
79
80        return result;
81
82
83    }
84};