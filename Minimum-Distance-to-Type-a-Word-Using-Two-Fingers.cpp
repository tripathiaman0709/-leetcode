1class Solution {
2public:
3    int dp[301][27][27];
4    pair<int, int> getCoord(int pos) {
5        return {pos/6, pos%6};
6    }
7
8    int getDistance(int pos1, int pos2) {
9        auto[x1, y1] = getCoord(pos1);
10        auto[x2, y2] = getCoord(pos2);
11        return abs(x1 - x2) + abs(y1-y2);
12    }
13
14    int solve(string &word, int i, int f1, int f2) {
15        if(i >= word.length())
16            return 0;
17        
18        int curr = word[i] - 'A';
19
20        if(dp[i][f1][f2] != -1) {
21            return dp[i][f1][f2];
22        }
23
24        //non used
25        if(f1 == 26 && f2 == 26) {
26            return dp[i][f1][f2] = solve(word, i+1, curr, f2);
27        }
28
29        //f2 not used
30        if(f2 == 26) {
31            int moveF2 = solve(word, i+1, f1, curr);
32            int moveF1 = getDistance(f1, curr) + solve(word, i+1, curr, f2);
33
34            return dp[i][f1][f2] = min(moveF1, moveF2);
35        }
36
37        //both used
38        int moveF1 = getDistance(f1, curr) + solve(word, i+1, curr, f2);
39
40
41        int moveF2 = getDistance(f2, curr) + solve(word, i+1, f1, curr);
42
43        return dp[i][f1][f2] = min(moveF1, moveF2);
44    }
45    int minimumDistance(string word) {
46
47        memset(dp, -1, sizeof(dp));
48        return solve(word, 0, 26, 26);
49    }
50};
51