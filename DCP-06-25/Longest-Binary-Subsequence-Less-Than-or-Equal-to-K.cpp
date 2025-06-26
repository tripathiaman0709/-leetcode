class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.length();
        long long powerValue = 1;
        long long total = 0;
        int length = 0;

        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '0') {
                length++;
            } else {
                if(total+powerValue <= k){
                    total+=powerValue;
                    length++;
                }
            }
            if(powerValue <= k){
                powerValue*=2;
            }
       }

        return length;
    }
};
