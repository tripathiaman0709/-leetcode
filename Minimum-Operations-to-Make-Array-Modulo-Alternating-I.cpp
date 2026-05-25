1class Solution {
2public:
3
4    int dist(int a, int b, int k) {
5
6        int d = abs(a - b);
7
8        return min(d, k - d);
9    }
10
11    int minOperations(vector<int>& v, int k) {
12
13        int n = v.size();
14
15        int ans = INT_MAX;
16
17        for(int evenRem = 0; evenRem < k; evenRem++) {
18
19            for(int oddRem = 0; oddRem < k; oddRem++) {
20
21                if(evenRem == oddRem) continue;
22
23                int cur = 0;
24
25                for(int i = 0; i < n; i++) {
26
27                    int rem = v[i] % k;
28
29                    if(i % 2 == 0) {
30                        cur += dist(rem, evenRem, k);
31                    }
32                    else {
33                        cur += dist(rem, oddRem, k);
34                    }
35                }
36
37                ans = min(ans, cur);
38            }
39        }
40
41        return ans;
42    }
43};