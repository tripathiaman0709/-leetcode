1class Solution {
2public:
3    int numberOfSpecialChars(string s) {
4
5        vector<int> lower(26, 0);
6        vector<int> upper(26, 0);
7
8        int n = s.size();
9
10        for(int i = 0; i < n; i++) {
11
12            if(islower(s[i])) {
13                lower[s[i]-'a'] = i + 1;
14            }
15        }
16
17        for(int i = n-1; i >= 0; i--) {
18
19            if(isupper(s[i])) {
20                upper[s[i]-'A'] = i + 1;
21            }
22        }
23
24        int ans = 0;
25
26        for(int i = 0; i < 26; i++) {
27
28            if(lower[i] && upper[i] &&
29               lower[i] < upper[i]) {
30
31                ans++;
32            }
33        }
34
35        return ans;
36    }
37};