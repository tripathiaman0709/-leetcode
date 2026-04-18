1class Solution {
2public:
3
4    int rev(int n){
5        //will use stoll
6        string s=to_string(n);
7        reverse(s.begin(),s.end());
8        int num=stoll(s);
9        return (int)num;
10    }
11
12    int mirrorDistance(int n) {
13        int ans=abs(rev(n)-n);
14        return ans;
15    }
16};