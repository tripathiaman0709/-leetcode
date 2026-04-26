1class Solution {
2public:
3    bool isVowel(char c){
4        return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
5    }
6
7    static bool cmp(const vector<int>& a, const vector<int>& b){
8        if(a[0] != b[0]) return a[0] > b[0];
9        return a[1] < b[1];
10    }
11
12    string sortVowels(string s) {
13        int n = s.size();
14
15        unordered_map<char,int> freq;
16        unordered_map<char,int> first;
17
18        // collect freq + first occurrence
19        for(int i = 0; i < n; i++){
20            if(isVowel(s[i])){
21                freq[s[i]]++;
22                if(first.find(s[i]) == first.end()){
23                    first[s[i]] = i;
24                }
25            }
26        }
27
28        // build vector: {freq, firstIdx, char}
29        vector<vector<int>> v;
30        for(auto &it : freq){
31            v.push_back({it.second, first[it.first], it.first});
32        }
33
34        sort(v.begin(), v.end(), cmp);
35
36        // flatten
37        vector<char> ordered;
38        for(auto &x : v){
39            for(int i = 0; i < x[0]; i++){
40                ordered.push_back((char)x[2]);
41            }
42        }
43
44        // rebuild
45        int j = 0;
46        for(int i = 0; i < n; i++){
47            if(isVowel(s[i])){
48                s[i] = ordered[j++];
49            }
50        }
51
52        return s;
53    }
54};