1class Solution {
2public:
3    int minimumPairRemoval(vector<int>& nums) {
4        int count = 0;
5
6        // This while loop keeps running until:
7        // 1) the array becomes non-decreasing, or
8        // 2) the array size becomes 1 (everything got merged)
9        while (nums.size() > 1) {
10            bool isSorted = true;
11            int minSum = INT_MAX;   // tracks the minimum adjacent pair sum
12            int targetIndex = -1;  // index of the left element of that pair
13
14            // Traverse all adjacent pairs
15            for (int i = 0; i < nums.size() - 1; i++) {
16                int sum = nums[i] + nums[i + 1];
17
18                // Check if array is still sorted
19                if (nums[i] > nums[i + 1]) {
20                    isSorted = false; // array is not sorted yet
21                }
22
23                // Use strictly less to pick the leftmost pair
24                // If the problem asked for the rightmost one,
25                // we would use (sum <= minSum) instead
26                if (sum < minSum) {
27                    minSum = sum;
28                    targetIndex = i;
29                }
30            }
31
32            // If the array is already sorted, stop the simulation
33            if (isSorted) {
34                break;
35            }
36
37            count++;
38
39            // Replace the left element of the pair with their sum
40            nums[targetIndex] = minSum;
41
42            // Remove the right element of the pair
43            // Array length reduces here
44            nums.erase(nums.begin() + targetIndex + 1);
45        }
46
47        return count;
48    }
49};