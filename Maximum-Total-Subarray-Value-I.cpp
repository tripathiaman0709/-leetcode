1class Solution {
2public:
3    long long maxTotalValue(vector<int>& v, int k) {
4        int n=v.size();
5        int mini=INT_MAX;
6        int maxi=INT_MIN;
7        for(auto it:v){
8            mini=min(mini,it);
9            maxi=max(maxi,it);
10        }
11
12        long long ans=k*(long long)(maxi-mini);
13
14        return ans;
15    }
16};