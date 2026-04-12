1class Solution {
2public:
3    const int mod = 1e9 + 7;
4
5    long long find(long long base,long long exp){
6    long long res = 1;
7    while (exp > 0) {
8        if (exp % 2 == 1) res = (__int128)res * base % mod;
9        base = (__int128)base * base % mod;
10        exp /= 2;
11    }
12    return res % mod;
13    }
14    int maxValue(vector<int>& nums1, vector<int>& nums0) {
15        vector<pair<int,int>> a;
16        long long n = nums1.size(),ans = 0;
17        int last = 0;
18        for(int i = 0; i<n; i++){
19            if(nums0[i] == 0){
20               last += nums1[i];
21            } else{
22                a.push_back({nums1[i],nums0[i]});
23            }
24        }
25        sort(a.begin(),a.end(),[](auto &a1, auto&a2){
26            if(a1.first == a2.first) return a1.second < a2.second;
27            return a1.first > a2.first;
28        });
29
30
31        long long exp = 0;
32
33
34        for(int i = a.size()-1; i>=0; i--){
35            auto [one,zero] = a[i];
36            exp += zero;
37            long long first = find(2,exp);
38
39            long long rn  = find(2,one);
40
41            long long val = (first * (rn - 1 + mod) % mod) % mod;
42             ans = (ans + val) % mod;
43
44            exp += one;
45        }
46
47            long long first = find(2,exp);
48
49            long long rn  = find(2,last);
50
51            long long val = (first * (rn - 1 + mod) % mod) % mod;
52             ans = (ans + val) % mod;
53
54        return ans;
55        
56    }
57};