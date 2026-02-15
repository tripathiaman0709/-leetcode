1class Solution {
2public:
3    int firstUniqueFreq(vector<int>& nums) {
4        unordered_map<int, int> mpp;
5        unordered_map<int, int> freq;
6
7        for(int i=0; i<nums.size(); i++){
8            mpp[nums[i]]++;
9        }
10
11        for(auto &it: mpp){
12            freq[it.second]++;
13        }
14
15        for(auto it: nums){
16            if(freq[mpp[it]] == 1) return it;
17        }
18        return -1;
19    }
20};