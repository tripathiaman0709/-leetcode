class Solution {
public:
    long long minimumCost(int c1, int c2, int c12, int n1, int n2) {
        long long ans = 0;

        long long m = min(n1, n2);

        if (c12 < (long long)c1 + c2) {
            ans += m * c12;
            n1 -= m;
            n2 -= m;
        }

        if (n1 > 0) {
            ans += 1LL * n1 * min(c1, c12);
        }

        if (n2 > 0) {
            ans += 1LL * n2 * min(c2, c12);
        }

        return ans;
    }
};