class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        long long ans = 0;
        for (const auto& qr : queries) {
            int l = qr[0], r = qr[1];
            ans += (getOperations(r) - getOperations(l - 1) + 1) / 2;
        }
        return ans;
    }

private:
    long long getOperations(long long n) {
        if (n <= 0) return 0;
        long long res = 0;
        long long ops = 0;
        for (long long powerOfFour = 1; powerOfFour <= n; powerOfFour *= 4) {
            long long l = powerOfFour;
            long long r = min(n, powerOfFour * 4 - 1);
            ++ops;
            res += (r - l + 1) * ops;
        }
        return res;
    }
};
