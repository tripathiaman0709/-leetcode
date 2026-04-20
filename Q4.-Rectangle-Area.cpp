1class Solution {
2public:
3    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
4        //very simple math
5
6        int ax=abs(ax1-ax2);
7        int ay=abs(ay1-ay2);
8
9        int bx=abs(bx1-bx2);
10        int by=abs(by1-by2);
11
12        int area1=ax*ay;
13        int area2=bx*by;
14
15        //now removing the coinciding area
16
17        int cx=(min(ax2,bx2)-max(ax1,bx1));
18        int cy=(min(ay2,by2)-max(ay1,by1));
19
20        int area3=0;
21        if(cx>0 && cy>0)area3=cx*cy;
22
23        return area1+area2-area3;
24    }
25};