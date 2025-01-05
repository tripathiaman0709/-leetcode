class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& q) {
        int n = s.size();
        vector<int> v(n + 1, 0); // Use n+1 to handle range efficiently

        // Process the queries
        for (const auto& query : q) {
            int f = query[0];
            int l = query[1];
            int dir = query[2] == 1 ? 1 : -1;

            v[f] += dir;
            if (l + 1 < n) v[l + 1] -= dir;
        }

        // Calculate prefix sum
        for (int i = 1; i < n; ++i) {
            v[i] += v[i - 1];
        }

        // Build the result string
        string ans = "";
        for (int i = 0; i < n; ++i) {
            int x = s[i] - 'a';
            int y = v[i];
            int z = (x + y) % 26;

            if (z < 0) z += 26; // Handle negative indices
            ans += char('a' + z);
        }
        return ans;
    }
};
