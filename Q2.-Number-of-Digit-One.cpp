1class Solution {
2public:
3    int countDigitOne(int n) {
4        long long ans = 0;
5
6        for(long long place = 1; place <= n; place *= 10) {
7            long long left = n / (place * 10);
8            long long curr = (n / place) % 10;
9            long long right = n % place;
10
11            if(curr == 0) {
12                ans += left * place;
13            }
14            else if(curr == 1) {
15                ans += left * place + (right + 1);
16            }
17            else {
18                ans += (left + 1) * place;
19            }
20        }
21
22        return (int)ans;
23    }
24};