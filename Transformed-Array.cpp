1class Solution {
2public:
3    vector<int> constructTransformedArray(vector<int>& v) {
4        int n = v.size();
5        vector<int>result(n);
6        for (int i = 0; i < n; ++i) {
7            if (v[i] == 0) {
8                result[i] = v[i];
9            } else {
10                int x = v[i] % n;
11                int targetIndex = (i + n + x) % n;
12                result[i] = v[targetIndex];
13            }
14        }
15        return result;
16    }
17};
18