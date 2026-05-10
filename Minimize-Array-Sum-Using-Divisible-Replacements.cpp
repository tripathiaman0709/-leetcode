1class Solution {
2public:
3
4    void sieve(vector<int>& isprime) {
5        int n = isprime.size();
6
7        if(n > 0) isprime[0] = 0;
8        if(n > 1) isprime[1] = 0;
9
10        for(int i = 2; i * i < n; i++) {
11            if(isprime[i]) {
12                for(int j = i * i; j < n; j += i) {
13                    isprime[j] = 0;
14                }
15            }
16        }
17    }
18
19    long long minArraySum(vector<int>& v) {
20
21        int n = v.size();
22
23        sort(v.begin(), v.end());
24
25        if(v[0] == 1) return n;
26        if(v[0] == v[n - 1]) return 1LL * n * v[0];
27
28        int mx = v.back();
29
30        vector<int> isprime(mx + 1, 1);
31        sieve(isprime);
32
33        vector<int> freq(mx + 1, 0);
34
35        for(int x : v) freq[x]++;
36
37        vector<int> smallest(mx + 1, -1);
38
39        // assign smallest divisor present in array
40        for(int d = 2; d <= mx; d++) {
41
42            if(freq[d] == 0) continue;
43
44            for(int multiple = d; multiple <= mx; multiple += d) {
45
46                // only composite numbers can change
47                if(!isprime[multiple] && smallest[multiple] == -1) {
48                    smallest[multiple] = d;
49                }
50            }
51        }
52
53        long long ans = 0;
54
55        for(int x : v) {
56
57            if(!isprime[x] && smallest[x] != -1) {
58                ans += smallest[x];
59            }
60            else {
61                ans += x;
62            }
63        }
64
65        return ans;
66    }
67};