1class Solution {
2public:
3    int minimumDifference(vector<int>& v, int k) {
4        int n=v.size();
5        if(k==1){
6            return 0;
7        }
8        sort(v.begin(),v.end());
9        int ans=INT_MAX;
10        for(int i=0;i<=n-k;i++){
11            int diff=v[i+k-1]-v[i];
12            ans=min(ans,diff);
13        }
14
15        return ans;
16
17    }
18};