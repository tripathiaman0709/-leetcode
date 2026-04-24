1class Solution {
2public:
3    int furthestDistanceFromOrigin(string s) {
4        int n=s.size();
5        int count=0;
6        int sum=0;
7        for(int i=0;i<n;i++){
8            if(s[i]=='L')sum--;
9            if(s[i]=='R')sum++;
10            if(s[i]=='_')count++;
11        }
12
13        if(sum<0)sum*=-1;
14        sum+=count;
15
16        return sum;
17    }
18};