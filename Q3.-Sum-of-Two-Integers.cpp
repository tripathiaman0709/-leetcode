1class Solution {
2public:
3    int getSum(int a, int b) {
4        int sum = a;
5        int carry = b;
6
7        while (carry != 0) {
8            int newSum = sum ^ carry;
9            int newCarry = (sum & carry) << 1;
10
11            sum = newSum;
12            carry = newCarry;
13        }
14
15        return sum;
16    }
17};