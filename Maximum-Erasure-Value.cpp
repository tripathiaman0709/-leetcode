class Solution {
public:
    int maximumUniqueSubarray(vector<int>& v) {
        int n = v.size();
        unordered_set<int> st;

        int left = 0, right = 0;
        int sum = 0, maxSum = 0;

        while (right < n) {
            if (st.find(v[right]) == st.end()) {
                st.insert(v[right]);
                sum += v[right];
                maxSum = max(maxSum, sum);
                right++;
            } else {
                st.erase(v[left]);
                sum -= v[left];
                left++;
            }
        }

        return maxSum;
    }
};
