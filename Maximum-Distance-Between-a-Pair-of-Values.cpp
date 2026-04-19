1class Solution {
2public:
3    int maxDistance(vector<int>& v1, vector<int>& v2) {
4        int n = v1.size(), m = v2.size();
5        int i = 0, j = 0, maxi = 0;
6
7        while (i < n && j < m) {
8            if (v2[j] >= v1[i]) {
9                maxi = max(maxi, j - i);
10                j++; 
11            } else {
12                i++;  
13            }
14        }
15        return maxi;
16    }
17};