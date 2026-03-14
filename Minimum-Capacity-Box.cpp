1class Solution {
2public:
3    int minimumIndex(vector<int>& v, int k) {
4        int n=v.size();
5        int mini=1000;
6        int ans=-1;
7        for(int i=0;i<n;i++){
8            if(v[i]==k){
9                return i;
10            }else if(v[i]>k && mini>v[i]){
11                ans=i;
12                mini=v[i];
13            }
14        }
15        return ans;
16    }
17};