1class Solution {
2public:
3    int minMoves(vector<int>& nums, int limit) {
4        int n = nums.size();
5
6        vector<int> diff(2 * limit + 2, 0);
7
8        for(int i = 0; i < n/2; i++) {
9
10            int a = nums[i];
11            int b = nums[n-1-i];
12
13            int minVal = min(a, b) + 1;
14            int maxVal = max(a, b) + limit;
15
16            diff[2] += 2;
17            diff[2*limit+1] -= 2;
18
19            //for moves = 1
20            diff[minVal]   += (-1);
21            diff[maxVal+1] -= (-1);
22
23            //for moves = 0 [a+b, a+b]
24            diff[a+b]   += (-1);
25            diff[a+b+1] -= (-1);
26        }
27
28        int result = INT_MAX;
29
30        for(int sum = 2; sum <= 2*limit; sum++) {
31            diff[sum] += diff[sum-1];
32
33            result = min(result, diff[sum]);
34        }
35
36        return result;
37    }
38};