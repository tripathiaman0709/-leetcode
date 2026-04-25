1class Solution {
2public:
3    bool validDigit(int n, int x) {
4        bool billu=false;
5        while(n>=10){
6            if(n%10==x)billu=true;
7            n/=10;
8        }
9        if(n==x)return false;
10        return billu;
11    }
12};