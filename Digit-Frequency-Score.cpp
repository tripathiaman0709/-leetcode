1class Solution {
2public:
3    int digitFrequencyScore(int n) {
4        unordered_map<int,int>mpp;
5        while(n){
6            int digit=n%10;
7            mpp[digit]++;
8            n/=10;
9        }
10        int sum=0;
11        for(auto it:mpp){
12            sum+=(it.first*it.second);
13        }
14
15        return sum;
16    }
17};