1/*
2Approach:
31. Convert problem into prefix difference: diff[i] = (#1s - #0s)
42. Two cases:
5   - diff == 0 -> no swap needed
6   - diff == +/- 2 -> fixed using one swap
73. Use hashmaps to track first occurrence and availability of characters outside.
8*/
9
10class Solution {
11public:
12    int longestBalanced(string s) {
13        int n = s.size();
14        vector<int> z(n), o(n), diff(n);
15        int cnt0 = 0, cnt1 = 0;
16
17        for (int i = 0; i < n; i++) {
18            if (s[i] == '0') cnt0++;
19            else cnt1++;
20            z[i] = cnt0;
21            o[i] = cnt1;
22            diff[i] = o[i] - z[i];
23        }
24
25        int maxLen = 0;
26        unordered_map<int, int> ind, ind0, ind1; 
27        ind[0] = -1;
28
29        for (int i = 0; i < n; i++) {
30            int pref = diff[i];
31
32            if (ind.count(pref)) {
33                maxLen = max(maxLen, i - ind[pref]);
34            }
35            
36            // Case: diff = -2 (need a '1')
37            if (ind.count(pref + 2)) { 
38                int j = ind[pref + 2];
39                int sub1s = o[i] - (j >= 0 ? o[j] : 0);
40
41                if (cnt1 > sub1s) maxLen = max(maxLen, i - j);
42                else if (ind1.count(pref + 2)) maxLen = max(maxLen, i - ind1[pref + 2]);
43            }
44
45            // Case: diff = +2 (need a '0')
46            if (ind.count(pref - 2)) { 
47                int j = ind[pref - 2];
48                int sub0s = z[i] - (j >= 0 ? z[j] : 0);
49
50                if (cnt0 > sub0s) maxLen = max(maxLen, i - j);
51                else if (ind0.count(pref - 2)) maxLen = max(maxLen, i - ind0[pref - 2]);
52            }
53            
54            if (!ind.count(pref)) ind[pref] = i;
55            if (!ind0.count(pref) && z[i] > 0) ind0[pref] = i;
56            if (!ind1.count(pref) && o[i] > 0) ind1[pref] = i;
57        }
58        return maxLen;
59    }
60};