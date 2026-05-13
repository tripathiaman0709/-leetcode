1class Solution {
2public:
3    int minFlips(string s) {
4
5        int n = s.size();
6
7        if (n < 3) return 0;
8
9        int c0 = 0;
10        int c1 = 0;
11
12        for (char ch : s) {
13            if (ch == '0') c0++;
14            else c1++;
15        }
16
17        // Case 1: All 0s
18        int cost1 = c1;
19
20        // Case 2: All 1s
21        int cost2 = c0;
22
23        // Case 3: Only one 1
24        int cost3 = (c1 == 0 ? 0 : c1 - 1);
25
26        // Case 4: Two 1s at extreme ends
27        int cost4 = INT_MAX;
28
29        if (s.front() == '1' && s.back() == '1') {
30            cost4 = c1 - 2;
31        }
32
33        return min({cost1, cost2, cost3, cost4});
34    }
35};