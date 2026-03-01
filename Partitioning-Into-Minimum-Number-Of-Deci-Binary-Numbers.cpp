1class Solution {
2public:
3    int minPartitions(string s) {
4        int maxi=0;
5        int n=s.size();
6        for(int i=0;i<n;i++){
7            maxi=max(maxi,s[i]-48);
8        }
9        return maxi;
10    }
11};