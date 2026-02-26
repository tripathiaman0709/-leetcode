1class Solution {
2public:
3    string maximumXor(string s, string t) {
4        int cnt0 = 0, cnt1 = 0;
5        for(char c : t){
6            if(c == '0') cnt0++;
7            else cnt1++;
8        }
9
10        string ans;
11        ans.reserve(s.size());
12
13        for(char c : s){
14            if(c == '1'){
15                if(cnt0 > 0){
16                    ans.push_back('1');
17                    cnt0--;
18                }else{
19                    ans.push_back('0');
20                    cnt1--;
21                }
22            }else{
23                if(cnt1 > 0){
24                    ans.push_back('1');
25                    cnt1--;
26                }else{
27                    ans.push_back('0');
28                    cnt0--;
29                }
30            }
31        }
32        return ans;
33    }
34};