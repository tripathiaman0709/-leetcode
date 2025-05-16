class Solution {
public:
    bool ham(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        int cnt = 0;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) cnt++;
        }
        return cnt == 1;
    }

    vector<string> getWordsInLongestSubsequence(vector<string>& w, vector<int>& g) {
        int n = w.size();
        vector<int> LIS(n, 1), prev(n, -1);
        int lis = 0, maxi = 1;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (g[j] != g[i] && ham(w[j], w[i]) && LIS[j] + 1 > LIS[i]) {
                    LIS[i] = LIS[j] + 1;
                    prev[i] = j;
                }
            }
            if (LIS[i] > maxi) {
                maxi = LIS[i];
                lis = i;
            }
        }

        vector<string> ans;
        while (lis != -1) {
            ans.push_back(w[lis]);
            lis = prev[lis];
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
