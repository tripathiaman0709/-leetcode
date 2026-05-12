1class Solution {
2public:
3
4    static bool comp(vector<int>& a, vector<int>& b) {
5        if(a[1] == b[1]) return a[0] < b[0];
6        return a[1] > b[1];
7    }
8
9    int minimumEffort(vector<vector<int>>& v) {
10        int n = v.size();
11
12        sort(v.begin(), v.end(), comp);
13        
14        int maxi=-1;
15        for(int i=0;i<n;i++){
16            maxi=max(maxi,v[i][1]);
17        }
18
19        int ans=maxi;
20        int rem=0;
21        for(int i=0;i<n;i++){
22            if(ans<v[i][1]){
23                int extra=min(v[i][0],(v[i][1]-ans));
24                rem+=extra;
25                ans+=extra;
26
27                ans-=(v[i][0]);
28            }else{
29                ans-=(v[i][0]);
30            }
31        }
32        
33        return maxi+rem;
34    }
35};