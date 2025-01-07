class Solution {
public:
    bool check(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        if (m < n) {
            return false;
        }
        for (int i = 0; i <= m - n; i++) { 
            string s = s2.substr(i, n);
            if (s == s1) {
                return true;
            }
        }
        return false;
    }

    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        int n = words.size();

        for (int i = 0; i < n; i++) {
            string s1 = words[i];
            for (int j = 0; j < n; j++) { 
                if (i != j) { 
                    string s2 = words[j];
                    if (check(s1, s2)) {
                        ans.push_back(s1);
                        break; 
                    }
                }
            }
        }
        return ans;
    }
};
