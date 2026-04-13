1class Solution {
2public:
3    int getMinDistance(vector<int>& v, int k, int s) {
4        int n=v.size();
5        int ans=INT_MAX;
6        for(int i=0;i<n;i++){
7            if(v[i]==k){
8                ans=min(ans,abs(i-s));
9            }
10        }
11        return ans;
12    }
13};