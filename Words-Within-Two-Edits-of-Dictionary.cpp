1class Solution {
2public:
3    vector<string> twoEditWords(vector<string>& queries,
4                                vector<string>& dictionary) {
5        vector<string> result;
6
7        for (string& query : queries) {
8            
9            for (string& s : dictionary) {
10                int diff = 0;
11
12                for (int i = 0; i < query.size(); i++) {
13                    if (query[i] != s[i]) {
14                        ++diff;
15                    }
16
17                    if(diff > 2)
18                        break;
19                }
20
21                if (diff <= 2) {
22                    result.push_back(query);
23                    break;
24                }
25            }
26        }
27        return result;
28    }
29};
30