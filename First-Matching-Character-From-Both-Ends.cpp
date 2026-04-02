1class Solution {
2public:
3    int firstMatchingIndex(string s) {
4        int n=s.size();
5        for(int i=0;i<=n/2;i++){
6            if(s[i]==s[n-i-1]){
7                return i;
8            }
9        }
10        return -1;
11    }
12};