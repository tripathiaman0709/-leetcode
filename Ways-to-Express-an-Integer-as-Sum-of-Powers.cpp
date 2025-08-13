class Solution {
public:
    int dp[301][6][302];
    int M=1e9+7;

    long long powerLL(int a, int b) {
        long long res = 1;
        for (int i = 0; i < b; i++) res *= a;
        return res;
    }

    int solve(int val, int x, int num) {
        if (val == 0) return 1; 
        if (val < 0) return 0;

        if(dp[val][x][num]!=-1){
            return dp[val][x][num];
        }

        long long p = powerLL(num, x);
        if (p > val) return 0;

        // pick or not pick
        int pick = solve(val - p, x, num + 1);
        int notpick = solve(val, x, num + 1);

        return dp[val][x][num]=(pick + notpick)%M;
    }

    int numberOfWays(int n, int x) {
        int start=1;
        memset(dp, -1, sizeof(dp));
        return solve(n, x, start) % M;
    }
};
