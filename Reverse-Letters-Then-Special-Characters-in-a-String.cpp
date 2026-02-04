1class Solution {
2public:
3    string reverseByType(string v) {
4        int n=v.size();
5        stack<char>lower;
6        stack<char>special;
7
8        for(int i=0;i<n;i++){
9            if(v[i]>=97 && v[i]<=123){
10                lower.push(v[i]);
11            }else{
12                special.push(v[i]);
13            }
14        }
15        string ans="";
16        for(int i=0;i<n;i++){
17            if(v[i]>=97 && v[i]<=123){
18                ans.push_back(lower.top());
19                lower.pop();
20            }else{
21                ans.push_back(special.top());
22                special.pop();
23            }
24        }
25
26        return ans;
27    }
28};