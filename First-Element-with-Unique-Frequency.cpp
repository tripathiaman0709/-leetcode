1class Solution {
2public:
3    int firstUniqueFreq(vector<int>& v) {
4        int n=v.size();
5        unordered_map<int,int>mpp;
6        for(int i=0;i<n;i++){
7            mpp[v[i]]++;
8        }
9        //now finding unique frequency
10        vector<int>freq;
11        for(auto it:mpp){
12            freq.push_back(it.second);
13        }
14        sort(freq.begin(),freq.end());
15        for(int i=0;i<n;i++){
16            int f=mpp[v[i]];
17
18            auto lb=lower_bound(freq.begin(),freq.end(),f)-freq.begin();
19            auto ub=upper_bound(freq.begin(),freq.end(),f)-freq.begin()-1;
20
21            if(lb==ub){
22                return v[i];
23            }
24        }
25        return -1;
26    }
27};