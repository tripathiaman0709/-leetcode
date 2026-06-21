1class Solution {
2public:
3    int maxIceCream(vector<int>& v, int k) {
4        if (v.empty()) return 0;
5    
6        int max_val = *max_element(v.begin(), v.end());
7        vector<int> count(max_val + 1, 0);
8        
9        for (int it : v) {
10            count[it]++;
11        }
12        
13        int ans = 0;
14        
15        for (int cost = 1; cost <= max_val; ++cost) {
16            if (count[cost] > 0) {
17                int take = min(count[cost], k / cost);
18                ans += take;
19                k -= take * cost;
20                
21                if (k < cost) {
22                    break;
23                }
24            }
25        }
26        
27        return ans;
28    }
29};