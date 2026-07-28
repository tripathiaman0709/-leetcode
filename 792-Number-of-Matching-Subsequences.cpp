class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {

        unordered_map<char, vector<int>> mpp;

        // Store indices of each character
        for(int i = 0; i < s.size(); i++) {
            mpp[s[i]].push_back(i);
        }

        int count = 0;

        // Check each word
        for(int i = 0; i < words.size(); i++) {

            string str = words[i];
            bool check = true;
            int prev = -1;

            for(int j = 0; j < str.size(); j++) {

                // Character doesn't exist in s
                if(mpp.find(str[j]) == mpp.end()) {
                    check = false;
                    break;
                }

                const vector<int> &vec = mpp[str[j]];

                auto it = upper_bound(vec.begin(), vec.end(), prev);

                if(it == vec.end()) {
                    check = false;
                    break;
                }

                prev = *it;
            }

            if(check) {
                count++;
            }
        }

        return count;
    }
};