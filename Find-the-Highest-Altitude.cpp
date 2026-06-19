1class Solution {
2public:
3    int largestAltitude(vector<int>& a) {
4        int n=a.size();
5        vector<int>pre(n,0);
6        pre[0]=a[0];
7        for(int i=1;i<n;i++){
8            pre[i]=pre[i-1]+a[i];
9        }
10        int maxi=0;
11        for(int i=0;i<n;i++){
12            maxi=max(pre[i],maxi);
13        }
14        return maxi;
15    }
16};