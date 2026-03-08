1class Solution {
2public:
3    void fun(int n, string &curr, vector<string> &ans) {
4        if (curr.size() == n) {
5            ans.push_back(curr);
6            return;
7        }
8
9        for (char i = 0; i <= 1; i++) {
10            char ch = '0' + i;
11            curr.push_back(ch);
12            fun(n, curr, ans);
13            curr.pop_back();
14        }
15    }
16
17    string findDifferentBinaryString(vector<string> &v) {
18        int n = v.size();
19        unordered_set<string> s(v.begin(), v.end());
20        vector<string> vec;
21        string curr = "";
22
23        fun(n, curr, vec);
24
25        for (auto &str : vec) {
26            if (!s.count(str)) {
27                return str;
28            }
29        }
30        return "";
31    }
32};