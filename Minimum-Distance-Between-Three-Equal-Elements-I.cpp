1class Solution {
2public:
3    int minimumDistance(vector<int>& v) {
4        int n=v.size();
5        unordered_map<int,vector<int>>mpp;
6        for(int i=0;i<n;i++){
7            mpp[v[i]].push_back(i);
8        }
9
10        int ans=INT_MAX;
11
12        for(auto it:mpp){
13            vector<int>vec=it.second;
14            if(vec.size()<3){
15                continue;
16            }
17            for(int i=0;i<vec.size()-2;i++){
18                int val=abs(vec[i]-vec[i+1])+abs(vec[i+1]-vec[i+2])+abs(vec[i]-vec[i+2]);
19                ans=min(ans,val);
20            }
21        }
22
23        if(ans==INT_MAX){
24            return -1;
25        }
26
27        return ans;
28    }
29};