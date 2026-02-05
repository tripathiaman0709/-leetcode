1class Solution {
2public:
3    int lis(vector<int>& nums){
4        vector<int> res;
5        for(int &x : nums){
6            if(res.empty() || res.back() < x){
7                res.push_back(x);
8                continue;
9            }
10            auto it = lower_bound(res.begin(), res.end(), x);
11            *it = x;
12        }
13        return res.size();
14    }
15    int longestSubsequence(vector<int>& nums) {
16        int best = 0;
17        for(int i = 0; i<31; i++){
18            vector<int> curr;
19            for(int&x : nums){
20                if(x & (1 << i)){
21                    curr.push_back(x);
22                }
23            }
24            best = max(best, lis(curr));
25        }
26        return best;
27    }
28};