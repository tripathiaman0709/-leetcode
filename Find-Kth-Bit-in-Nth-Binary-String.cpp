1class Solution {
2public:
3    char findKthBit(int n, int k) {
4        // Base case: When n = 1, the binary string is "0"
5        if (n == 1) return '0';
6        
7        // Find the length of the current string Sn, which is 2^n - 1
8        int length = (1 << n) - 1;
9        
10        // Find the middle position
11        int mid = length / 2 + 1;
12        
13        // If k is the middle position, return '1'
14        if (k == mid) return '1';
15        
16        // If k is in the first half, find the bit in Sn-1
17        if (k < mid) return findKthBit(n - 1, k);
18        
19        // If k is in the second half, find the bit in Sn-1 and invert it
20        return findKthBit(n - 1, length - k + 1) == '0' ? '1' : '0';
21    }
22};