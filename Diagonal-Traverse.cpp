class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        unordered_map<int, vector<int>> diag;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                diag[i + j].push_back(mat[i][j]);
            }
        }

        vector<int> ans;
        ans.reserve(n * m);

        for (int s = 0; s <= n + m - 2; s++) {
            if (s % 2 == 0) {
                // reversing for upward diagonals
                reverse(diag[s].begin(), diag[s].end());
            }
            for (int val : diag[s]) {
                ans.push_back(val);
            }
        }

        return ans;
    }
};
