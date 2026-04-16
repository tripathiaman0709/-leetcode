1class Solution {
2public:
3    bool isPalindrome(int x) {
4        if(x<0){
5            return false;
6        }
7        string s=to_string(x);
8        int n=s.size();
9        for(int i=0;i<n/2;i++){
10            if(s[i]!=s[n-i-1])return false;
11        }
12        return true;
13    }
14};