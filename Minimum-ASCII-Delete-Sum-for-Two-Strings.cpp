1class Solution {
2public:
3    int dp[1001][1001];
4
5    int solve(string &s1, string &s2, int i, int j) {
6        if (i == s1.size() && j == s2.size())
7            return 0;
8
9        if (i == s1.size()) {
10            int sum = 0;
11            for (int k = j; k < s2.size(); k++)
12                sum += s2[k];
13            return sum;
14        }
15
16        if (j == s2.size()) {
17            int sum = 0;
18            for (int k = i; k < s1.size(); k++)
19                sum += s1[k];
20            return sum;
21        }
22
23        if (dp[i][j] != -1)
24            return dp[i][j];
25
26        if (s1[i] == s2[j]) {
27            return dp[i][j] = solve(s1, s2, i + 1, j + 1);
28        }
29
30        int delete_s1 = s1[i] + solve(s1, s2, i + 1, j);
31        int delete_s2 = s2[j] + solve(s1, s2, i, j + 1);
32
33        return dp[i][j] = min(delete_s1, delete_s2);
34    }
35
36    int minimumDeleteSum(string s1, string s2) {
37        memset(dp, -1, sizeof(dp));
38        return solve(s1, s2, 0, 0);
39    }
40};
41