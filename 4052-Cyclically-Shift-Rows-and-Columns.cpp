class Solution {
public:
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& v,
                                    vector<int>& r, vector<int>& c) {

        vector<vector<int>> ans = v;

        // Row shifts
        for(int i = 0; i < n; i++) {
            int k = r[i] % n;

            for(int j = 0; j < n; j++) {
                ans[i][(j - k + n) % n] = v[i][j];
            }
        }

        // Column shifts
        vector<vector<int>> temp = ans;

        for(int j = 0; j < n; j++) {
            int k = c[j] % n;

            for(int i = 0; i < n; i++) {
                ans[(i - k + n) % n][j] = temp[i][j];
            }
        }

        return ans;
    }
};