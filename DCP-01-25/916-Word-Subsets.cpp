class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;

        // Step 1: Compute max frequencies for all words in words2
        unordered_map<char, int> mpp2;
        for (const string& word : words2) {
            unordered_map<char, int> freq;
            for (char ch : word) {
                freq[ch]++;
            }
            for (auto it : freq) {
                mpp2[it.first] = max(mpp2[it.first], it.second);
            }
        }

        // Step 2: Check each word in words1
        for (const string& word : words1) {
            unordered_map<char, int> mpp1;
            for (char ch : word) {
                mpp1[ch]++;
            }

            // Validate against mpp2
            bool isValid = true;
            for (auto it : mpp2) {
                if (mpp1[it.first] < it.second) {
                    isValid = false;
                    break;
                }
            }

            if (isValid) {
                ans.push_back(word);
            }
        }

        return ans;
    }
};
