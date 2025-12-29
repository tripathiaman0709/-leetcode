1class Solution {
2public:
3    unordered_map<string, bool> t;
4
5    bool solve(string curr, unordered_map<string, vector<char>>& mp, int idx, string above) {
6        if(curr.length() == 1) { //pyramid is formed and we are at the top
7            return true;
8        }
9
10        string key = curr + "_" + to_string(idx) + "_" + above;
11
12        if(t.count(key))
13            return t[key];
14
15        if(idx == curr.length()-1) { //time to move to next row i.e. abocve row
16            return t[key] =  solve(above, mp, 0, "");
17        }
18
19        string pair = curr.substr(idx, 2);
20        if(mp.find(pair) == mp.end()) {
21            return t[key] = false;
22        }
23
24        for(char &ch : mp[pair]) {
25            above.push_back(ch); //DO
26
27            if(solve(curr, mp, idx+1, above) == true) //EXPLORE
28                return t[key] = true;
29            
30            above.pop_back(); //UNDO
31        }
32
33        return t[key] = false;
34    }
35
36    bool pyramidTransition(string bottom, vector<string>& allowed) {
37        unordered_map<string, vector<char>> mp;
38
39        for(auto& pattern : allowed) {
40            mp[pattern.substr(0, 2)].push_back(pattern[2]); //"ABC"
41        }
42
43        return solve(bottom, mp, 0, "");
44    }
45};
46
47