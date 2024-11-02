class Solution {
public:
    int maxRepeating(string s, string s1) {
        int count = 0;
        string repeated = s1;

        // Keep increasing the repetition of s1 until it no longer appears in s
        while (s.find(repeated) != string::npos) {
            count++;
            repeated += s1;  // Extend the repeated string by one more s1
        }

        return count;
    }
};
