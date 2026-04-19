1class Solution {
2public:
3    int trailingZeroes(int n) {
4        int count = 0;
5
6        while (n) {
7            n /= 5;
8            count += n;
9        }
10
11        return count;
12    }
13};