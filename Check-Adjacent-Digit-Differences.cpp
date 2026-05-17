1class Solution {
2public:
3    bool isAdjacentDiffAtMostTwo(string s) {
4        int n=s.size();
5        for(int i=0;i<n-1;i++){
6            if(abs(s[i]-s[i+1])>2)return false;
7        }
8        return true;
9    }
10};