class Solution {
public:
    long long calculateScore(string s) {
        int n = s.size();
        long long score = 0;

        // Map to store indices of each character
        unordered_map<char, vector<int>> charIndices;

        for (int i = 0; i < n; i++) {
            char mirror = 'z' - (s[i] - 'a'); // Calculate the mirror character

            // Check if there's an unmarked index for the mirror character
            if (charIndices.find(mirror) != charIndices.end() && !charIndices[mirror].empty()) {
                int j = charIndices[mirror].back();
                charIndices[mirror].pop_back(); // Remove the used index

                // Add to the score
                score += (i - j);
            } else {
                // Add the current index to the map for the current character
                charIndices[s[i]].push_back(i);
            }
        }

        return score;
    }
};
