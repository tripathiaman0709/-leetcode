1class Solution {
2public:
3    int vowelConsonantScore(string s) {
4        int n=s.size();
5        int v=0;
6        int c=0;
7        for(int i=0;i<n;i++){
8            if(s[i]==97 || s[i]==101 || s[i]==105 || s[i]==111 || s[i]==117){
9                v++;
10            }else if(s[i]>97 && s[i]<124){
11                c++;
12            }
13        }
14        if(c==0){
15            return 0;
16        }
17        return v/c;
18    }
19};