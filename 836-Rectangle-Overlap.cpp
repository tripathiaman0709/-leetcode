class Solution {
public:
    bool isRectangleOverlap(vector<int>& r1, vector<int>& r2) {
        int x11=r1[0];
        int x21=r1[2];
        int y11=r1[1];
        int y21=r1[3];


        int x12=r2[0];
        int x22=r2[2];
        int y12=r2[1];
        int y22=r2[3];


        return (x11 < x22 && x12 < x21 && y11 < y22 && y12 < y21);
    }
};