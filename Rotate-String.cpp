1class Solution {
2public:
3    bool rotateString(string s, string goal) {
4        // Step 1: Length check
5        if (s.size() != goal.size()) return false;
6
7        // Step 2: Concatenate
8        string doubled = s + s;
9
10        // Step 3: Check substring
11        return doubled.find(goal) != string::npos;
12    }
13};