class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& s, vector<int>& e) {
        int n = s.size();
        vector<int> diff;

        diff.push_back(s[0]);  // free time before first event

        for (int i = 1; i < n; i++) {
            diff.push_back(s[i] - e[i - 1]);  // gap between events
        }

        diff.push_back(eventTime - e[n - 1]);  // free time after last event

        int i = 0, j = 0, sum = 0, ans = -1;
        int sz = diff.size();

        while (j < sz) {
            sum += diff[j];

            if (j - i + 1 == k+1) {
                ans = max(ans, sum);
                sum -= diff[i];
                i++;
            }

            j++;
        }

        return ans;
    }
};
