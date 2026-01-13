1class Solution {
2public:
3    int centeredSubarrays(vector<int>& v) {
4        //making all possible subarrays and finding the answer
5        int n=v.size();
6        int ans=0;
7        for(int i=0;i<n;i++){
8            int sum=0;
9            unordered_map<int,int>mpp;
10            for(int j=i;j<n;j++){
11                mpp[v[j]]++;
12                sum+=v[j];
13                if(mpp[sum]){
14                    ans++;
15                }
16            }
17        }
18        return ans;
19    }
20};