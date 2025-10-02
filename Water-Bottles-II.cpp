class Solution {
public:
    int maxBottlesDrunk(int a, int x) {
        int ans = a;
        while (a >= x) {
            a -= x - 1;
            x++;
            ans++;
        }
        return ans;
    }
};