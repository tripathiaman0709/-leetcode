class Solution {
public:
    long long minCost(vector<int>& v1, vector<int>& v2) {
        int n = v1.size(), m = v2.size();
        unordered_map<int, int> mpp;
        for (int x : v1) mpp[x]++;
        for (int x : v2) mpp[x]++;
        
        for (auto& it : mpp)
            if (it.second % 2 != 0) return -1;

        vector<int> basket1, basket2;
        unordered_map<int, int> mpp1, mpp2;
        for (int x : v1) mpp1[x]++;
        for (int x : v2) mpp2[x]++;

        for (auto& it : mpp1) {
            int total = mpp[it.first];
            int target = total / 2;
            if (it.second > target) {
                int count = it.second - target;
                for (int i = 0; i < count; ++i) basket1.push_back(it.first);
            }
        }

        for (auto& it : mpp2) {
            int total = mpp[it.first];
            int target = total / 2;
            if (it.second > target) {
                int count = it.second - target;
                for (int i = 0; i < count; ++i) basket2.push_back(it.first);
            }
        }

        if (basket1.size() != basket2.size()) return -1;

        sort(basket1.begin(), basket1.end());
        sort(basket2.rbegin(), basket2.rend());

        int globalMin = min(*min_element(v1.begin(), v1.end()),
                            *min_element(v2.begin(), v2.end()));

        long long sum = 0;
        for (int i = 0; i < basket1.size(); ++i) {
            sum += min({basket1[i], basket2[i], 2 * globalMin});
        }

        return sum;
    }
};
