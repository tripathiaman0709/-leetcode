1class Solution {
2public:
3    bool isUgly(int n) {
4        while(n>1){
5            if(n%5==0)n/=5;
6            else if(n%3==0)n/=3;
7            else if(n%2==0)n/=2;
8            else break;
9        }
10
11        if(n==1)return true;
12        return false;
13    }
14};