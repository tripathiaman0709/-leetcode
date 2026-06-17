1typedef long long ll;
2class Solution {
3public:
4    char processStr(string s, long long k) {
5        ll len = 0;
6        for(auto c:s){
7            if(islower(c)) len++;
8            else if(c=='*' && len>0) len--;
9            else if(c=='#') len *= 2;
10        }
11        if(k >= len) return '.';
12
13        for(int i = s.size()-1; i >= 0; --i){
14            char c = s[i];
15            if(islower(c)) {
16                if(k == len - 1) return c;
17                len--;
18            }
19            else if(c == '*') len++;
20            else if(c == '#') {
21                len /= 2;
22                if(k >= len) k -= len;
23            }
24            else if(c == '%') {
25                k = len - 1 - k;
26            }
27        }
28        return '.';
29    }
30};