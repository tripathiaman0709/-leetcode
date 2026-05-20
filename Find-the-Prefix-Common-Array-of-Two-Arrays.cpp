1class Solution {
2public:
3    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
4        int n = A.size();
5
6        vector<int> ans(n);
7        vector<int> freq(n + 1, 0);
8
9        int common = 0;
10
11        for (int i = 0; i < n; i++) {
12
13            freq[A[i]]++;
14            if (freq[A[i]] == 2)
15                common++;
16
17            freq[B[i]]++;
18            if (freq[B[i]] == 2)
19                common++;
20
21            ans[i] = common;
22        }
23
24        return ans;
25    }
26};