1class Solution {
2public:
3    bool checkStrings(string s1, string s2) {
4        array<string, 2> A, B;
5        for (int i = 0; i < s1.length(); i++) {
6            int off = i & 1;
7            A[off] += s1[i];
8            B[off] += s2[i];
9        }
10
11        for (int i = 0; i < 2; i++) {
12            sort(A[i].begin(), A[i].end());
13            sort(B[i].begin(), B[i].end());
14        }
15
16        return A == B;
17    }
18};