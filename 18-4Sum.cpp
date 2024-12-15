class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& v, int t) {
        int n = v.size();
        std::unordered_map<int, int> mpp;

        // Map each element to its index (ensuring no collisions)
        for (int i = 0; i < n; i++) {
            mpp[v[i]] = i;
        }

        std::set<std::vector<int>> st;  // To store unique results
        std::vector<std::vector<int>> sol;

        // Use unordered_map but check for large numbers carefully
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    // Ensure no overflow occurs while calculating req
                    long long req = (long long)t - v[i] - v[j] - v[k];

                    // Ensure req fits in an int range
                    if (req < INT_MIN || req > INT_MAX) {
                        continue;
                    }

                    // Now we check if the required value exists in the map and if its index is greater than k
                    if (mpp.find(req) != mpp.end()) {
                        if (mpp[req] > k) {
                            // Cast req to int explicitly
                            std::vector<int> ans = {v[i], v[j], v[k], static_cast<int>(req)};
                            std::sort(ans.begin(), ans.end());  // Sort to avoid duplicate sets
                            st.insert(ans);  // Insert into set to avoid duplicates
                        }
                    }
                }
            }
        }

        // Convert the set to a vector of vectors for the final result
        for (auto it : st) {
            sol.push_back(it);
        }

        return sol;
    }
};
