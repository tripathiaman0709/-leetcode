1class Solution {
2public:
3    int repeatedNTimes(vector<int>& v) {
4        int sz=v.size();
5        int n=sz/2;
6
7        unordered_map<int,int>mpp;
8
9        for(auto it:v){
10            mpp[it]++;
11        }
12
13        int ans=-1;
14        for(auto it:mpp){
15            if(it.second==n){
16                ans=it.first;
17                break;
18            }
19        }
20
21        return ans;
22    }
23};