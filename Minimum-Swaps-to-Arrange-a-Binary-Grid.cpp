1class Solution {
2public:
3    int minSwaps(vector<vector<int>>& grid) {
4        int n = grid.size();
5        vector<int> zeros(n);
6
7        // Count trailing zeros
8        for(int i = 0; i < n; i++) {
9            int count = 0;
10            for(int j = n-1; j >= 0; j--) {
11                if(grid[i][j] == 0) count++;
12                else break;
13            }
14            zeros[i] = count;
15        }
16
17        int swaps = 0;
18
19        for(int i = 0; i < n; i++) {
20            int required = n - i - 1;
21            int j = i;
22
23            while(j < n && zeros[j] < required) j++;
24
25            if(j == n) return -1;
26
27            while(j > i) {
28                swap(zeros[j], zeros[j-1]);
29                swaps++;
30                j--;
31            }
32        }
33
34        return swaps;
35    }
36};