1class Solution {
2public:
3    int hammingWeight(int n) {
4        int count=0;
5        while(n){
6            if(n%2)count++;
7            n/=2;
8        }
9        return count;
10    }
11};