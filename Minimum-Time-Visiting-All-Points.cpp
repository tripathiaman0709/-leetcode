1class Solution {
2public:
3    int minTimeToVisitAllPoints(vector<vector<int>>& v) {
4        int n=v.size();
5        int startx=v[0][0];
6        int starty=v[0][1];
7        int sum=0;
8        for(int i=1;i<n;i++){
9            int curx=v[i][0];
10            int cury=v[i][1];
11            int x=abs(curx-startx);
12            int y=abs(cury-starty);
13                int val=max(x,y);
14                sum+=val;
15            startx=curx;
16            starty=cury;
17        }
18        return sum;
19    }
20};