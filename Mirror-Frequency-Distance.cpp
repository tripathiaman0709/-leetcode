1class Solution {
2public:
3    int mirrorFrequency(string s) {
4        unordered_map<char,int> mpp;
5        for(char c : s) mpp[c]++;
6
7        unordered_map<char,char> alpha;
8        for(int i = 0; i < 26; i++){
9            alpha['a' + i] = 'z' - i;
10        }
11
12        unordered_map<char,char> digi;
13        for(int i = 0; i <= 9; i++){
14            digi['0' + i] = char('9' - i);
15        }
16
17        unordered_set<char> vis;
18        int sum = 0;
19
20        for(char c : s){
21            if(vis.count(c)) continue;
22
23            char mirror;
24            if(islower(c)) mirror = alpha[c];
25            else mirror = digi[c];
26
27            sum += abs(mpp[c] - mpp[mirror]);
28
29            vis.insert(c);
30            vis.insert(mirror);
31        }
32
33        return sum;
34    }
35};