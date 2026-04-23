1class Solution {
2public:
3    vector<long long> distance(vector<int>& v) {
4        int n = v.size();
5        vector<long long> ans(n);
6
7        unordered_map<int, vector<int>> mpp;
8
9        // store indices
10        for(int i = 0; i < n; i++) {
11            mpp[v[i]].push_back(i);
12        }
13
14        for(auto &p : mpp) {
15            vector<int> &idx = p.second;
16            int k = idx.size();
17
18            vector<long long> prefix(k, 0);
19
20            // build prefix sum
21            prefix[0] = idx[0];
22            for(int i = 1; i < k; i++) {
23                prefix[i] = prefix[i-1] + idx[i];
24            }
25
26            for(int j = 0; j < k; j++) {
27                long long left = 0, right = 0;
28
29                if(j > 0) {
30                    left = (long long)j * idx[j] - prefix[j-1];
31                }
32
33                if(j < k-1) {
34                    right = (prefix[k-1] - prefix[j]) - (long long)(k-j-1) * idx[j];
35                }
36
37                ans[idx[j]] = left + right;
38            }
39        }
40
41        return ans;
42    }
43};