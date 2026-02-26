1class Solution {
2public:
3
4    long long gcd(long long a, long long b){
5        return b ? gcd(b, a % b) : a;
6    }
7
8    map<tuple<int,long long,long long>, int> dp;
9
10    int solve(int ind, long long num, long long den, vector<int>& nums, long long k){
11
12        if(ind == nums.size()){
13            return (num == k && den == 1);
14        }
15
16        auto key = make_tuple(ind, num, den);
17        if(dp.count(key)) return dp[key];
18
19        int res = 0;
20
21        // multiply
22        {
23            long long nnum = num * nums[ind];
24            long long nden = den;
25            long long g = gcd(nnum, nden);
26            nnum /= g;
27            nden /= g;
28            res += solve(ind+1, nnum, nden, nums, k);
29        }
30
31        // divide
32        {
33            long long nnum = num;
34            long long nden = den * nums[ind];
35            long long g = gcd(nnum, nden);
36            nnum /= g;
37            nden /= g;
38            res += solve(ind+1, nnum, nden, nums, k);
39        }
40
41        // skip
42        res += solve(ind+1, num, den, nums, k);
43
44        return dp[key] = res;
45    }
46
47    int countSequences(vector<int>& nums, long long k) {
48        dp.clear();
49        return solve(0, 1, 1, nums, k);
50    }
51};