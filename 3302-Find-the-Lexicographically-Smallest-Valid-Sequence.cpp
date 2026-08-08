class Solution {
public:
    vector<int> validSequence(string s1, string s2) {
        int N = s1.size();
        int M = s2.size();

        int R = M - 1;
        int C = 0;
        vector<int> suff(N);
        for (int i = N - 1; i >= 0; i--) {
            suff[i] = C;
            if (R >= 0 && s1[i] == s2[R]) {
                R--;
                C++;
            }
        }

        vector<int> ans;
        bool changed = false;
        int j = 0; 

        for (int i = 0; i < N && j < M; i++) {
            if (s1[i] == s2[j]) {
                ans.push_back(i);
                j++;
            } else if (!changed && suff[i] >= M - 1 - j) {
                ans.push_back(i);
                j++;
                changed = true;
            }
        }

        if (j == M) {
            return ans;
        }
        return {};
    }
};