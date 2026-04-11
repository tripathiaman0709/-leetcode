1#include <bits/stdc++.h>
2using namespace std;
3
4class Solution {
5public:
6    vector<bool> isPrime;
7    vector<int> nextPrime, nextNonPrime;
8
9    void sieve(int limit) {
10        isPrime.assign(limit + 1, true);
11        isPrime[0] = isPrime[1] = false;
12
13        for (int i = 2; i * i <= limit; i++) {
14            if (isPrime[i]) {
15                for (int j = i * i; j <= limit; j += i) {
16                    isPrime[j] = false;
17                }
18            }
19        }
20
21        nextPrime.assign(limit + 2, -1);
22        nextNonPrime.assign(limit + 2, -1);
23
24        int lastPrime = -1, lastNonPrime = -1;
25
26        for (int i = limit; i >= 0; i--) {
27            if (isPrime[i]) lastPrime = i;
28            else lastNonPrime = i;
29
30            nextPrime[i] = lastPrime;
31            nextNonPrime[i] = lastNonPrime;
32        }
33    }
34
35    int minOperations(vector<int>& nums) {
36        int n = nums.size();
37        int maxVal = *max_element(nums.begin(), nums.end());
38
39        int limit = max(200000, maxVal + 100);
40        sieve(limit);
41
42        int operations = 0;
43
44        for (int i = 0; i < n; i++) {
45            if (i % 2 == 0) {
46                operations += nextPrime[nums[i]] - nums[i];
47            } else {
48                operations += nextNonPrime[nums[i]] - nums[i];
49            }
50        }
51
52        return operations;
53    }
54};