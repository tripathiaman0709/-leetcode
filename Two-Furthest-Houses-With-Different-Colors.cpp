1class Solution {
2public:
3    int maxDistance(vector<int>& v) {
4        int n=v.size();
5        //trying brute force approach
6        int maxi=0;
7        for(int i=0;i<n;i++){
8            for(int j=0;j<n;j++){
9                if(v[i]!=v[j]){
10                    maxi=max(maxi,j-i);
11                }
12            }
13        }
14        return maxi;
15    }
16};