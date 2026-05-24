1class Solution {
2public:
3    int n;
4    vector<int> t;
5
6    int solve(vector<int>& arr, int d, int i) {
7        if (t[i] != -1)
8            return t[i];
9
10        int result = 1; // count current index also
11
12        // move left
13        for (int j = i - 1; j >= max(0, i - d); j--) {
14            // can't jump further once taller/equal element appears
15            if (arr[j] >= arr[i])
16                break;
17            result = max(result, 1 + solve(arr, d, j));
18        }
19
20        // move right
21        for (int j = i + 1; j <= min(n - 1, i + d); j++) {
22            // can't jump further once taller/equal element appears
23            if (arr[j] >= arr[i])
24                break;
25            result = max(result, 1 + solve(arr, d, j));
26        }
27
28        return t[i] = result;
29    }
30
31    int maxJumps(vector<int>& arr, int d) {
32        n = arr.size();
33        t.resize(n, -1);
34
35        int maxJump = 1;
36        // We need to try from every index
37        for (int i = 0; i < n; i++) {
38            maxJump = max(maxJump, solve(arr, d, i));
39        }
40
41        return maxJump;
42    }
43};
44