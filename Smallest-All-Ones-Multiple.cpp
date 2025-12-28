1class Solution {
2public:
3
4    int minAllOneMultiple(int k) {
5        if (k == 1) return 1;
6
7        // Numbers made of only 1s can never be divisible by 2 or 5
8        if (k % 2 == 0 || k % 5 == 0) return -1;
9
10        int rem = 0;
11        for (int i = 1; i <= k; i++) {
12            rem = (rem * 10 + 1) % k;
13            if (rem == 0) return i;
14        }
15        return -1;        
16    }
17};