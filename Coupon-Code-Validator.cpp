1class Solution {
2public:
3    vector<string> validateCoupons(vector<string>& code,
4                                   vector<string>& businessLine,
5                                   vector<bool>& isActive) {
6
7        // Business line priority
8        unordered_map<string, int> priority = {
9            {"electronics", 0},
10            {"grocery", 1},
11            {"pharmacy", 2},
12            {"restaurant", 3}
13        };
14
15        vector<pair<int, string>> valid;
16
17        for (int i = 0; i < code.size(); i++) {
18            if (isActive[i] &&
19                priority.count(businessLine[i]) &&
20                isValidCode(code[i])) {
21
22                valid.push_back({priority[businessLine[i]], code[i]});
23            }
24        }
25
26        // Sort by priority, then by code
27        sort(valid.begin(), valid.end());
28
29        vector<string> result;
30        for (auto &p : valid) {
31            result.push_back(p.second);
32        }
33
34        return result;
35    }
36
37private:
38    bool isValidCode(const string& s) {
39        if (s.empty()) return false;
40        for (char c : s) {
41            if (!isalnum(c) && c != '_')
42                return false;
43        }
44        return true;
45    }
46};