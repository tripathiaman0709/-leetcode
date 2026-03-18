1class Solution {
2public:
3    int minCost(vector<int>& v1, vector<int>& v2) {
4        int n=v1.size();
5        int m=v2.size();
6        if(n!=m){
7            return -1;
8        }
9        unordered_map<int,int>mpp;
10        unordered_map<int,int>mpp1;
11        unordered_map<int,int>mpp2;
12
13        for(auto it:v1){
14            mpp[it]++;
15            mpp1[it]++;
16        }
17        for(auto it:v2){
18            mpp[it]++;
19            mpp2[it]++;
20        }
21        for(auto it:mpp){
22            if(it.second%2){
23                return -1;
24            }
25        }
26        int count=0;
27        int ans=0;
28        for(auto it:mpp){
29            int need=mpp[it.first]/2;
30            if(mpp1[it.first]==need)continue;
31
32            ans+=abs(need-mpp1[it.first]);
33        }
34        return ans/2;
35    }
36};