1class Solution {
2public:
3    bool judgeCircle(string s) {
4        int n=s.size();
5        int x=0;
6        int y=0;
7        for(int i=0;i<n;i++){
8            if(s[i]=='L')x--;
9            if(s[i]=='R')x++;
10
11            if(s[i]=='U')y++;
12            if(s[i]=='D')y--;
13        }
14
15        if(x==0 && y==0)return true;
16        return false;
17    }
18};