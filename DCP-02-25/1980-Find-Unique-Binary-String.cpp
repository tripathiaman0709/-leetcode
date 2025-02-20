class Solution {
public:
    void fun(int n, string &curr, vector<string> &ans) {
        if (curr.size() == n) {
            ans.push_back(curr);
            return;
        }

        for (char i = 0; i <= 1; i++) {
            char ch = '0' + i;
            curr.push_back(ch);
            fun(n, curr, ans);
            curr.pop_back();
        }
    }

    string findDifferentBinaryString(vector<string> &v) {
        int n = v.size();
        unordered_set<string> s(v.begin(), v.end());
        vector<string> vec;
        string curr = "";

        fun(n, curr, vec);

        for (auto &str : vec) {
            if (!s.count(str)) {
                return str;
            }
        }
        return "";
    }
};
