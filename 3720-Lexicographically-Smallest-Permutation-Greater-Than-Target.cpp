#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string lexGreaterPermutation(string s, string t) {
        int n = s.size();
        multiset<char> original;
        for (auto c : s) original.insert(c);

        string best = "";
        bool found = false;

        for (int i = 0; i < n; i++) {
            multiset<char> mlt = original;
            string prefix = t.substr(0, i);

            bool can_form_prefix = true;
            for (char c : prefix) {
                auto it = mlt.find(c);
                if (it == mlt.end()) {
                    can_form_prefix = false;
                    break;
                }
                mlt.erase(it);
            }
            if (!can_form_prefix) continue;

            auto it = mlt.upper_bound(t[i]);
            if (it == mlt.end()) continue;

            string cur = prefix + *it;
            mlt.erase(it);
            for (char ch : mlt) cur += ch;

            if (!found || cur < best) {
                best = cur;
                found = true;
            }
        }
        return found ? best : "";
    }
};