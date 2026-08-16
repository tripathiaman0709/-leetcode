class Solution {
public:
    bool stoneGameIX(vector<int>& v) {
        int c0 = 0;
        int c1 = 0;
        int c2 = 0;

        for(int &it : v) {
            if(it % 3 == 0) {
                c0++;
            } else if(it % 3 == 1) {
                c1++;
            } else {
                c2++;
            }
        }

        if(c0 % 2 == 0) { //even
            return (c1 >= 1 && c2 >= 1) && (c2 >= c1 || c1 >= c2);
        }

        return abs(c1 - c2) >= 3;
    }
};

