1class Solution {
2public:
3    vector<int> findGoodIntegers(int n) {
4        vector<int>v;
5        for(int i=0;i*i*i<=n;i++){
6            int cube=i*i*i;
7            v.push_back(cube);
8        }
9        unordered_map<int,int>mpp;
10        for(int i=0;i<v.size();i++){
11            for(int j=0;j<v.size();j++){
12                int sum=v[i]+v[j];
13                if(sum>n){
14                    continue;
15                }
16                mpp[sum]++;
17            }
18        }
19        vector<int>ans;
20        for(auto it:mpp){
21            if(it.second>2){
22                ans.push_back(it.first);
23            }
24        }
25        sort(ans.begin(),ans.end());
26        return ans;
27    }
28};