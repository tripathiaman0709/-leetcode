1class Solution {
2public:
3    int countCommas(int n) {
4        if(n<1000){
5            return 0;
6        }
7        if(n<=100000){
8            return (n-999);
9        }
10        return 0;
11    }
12};