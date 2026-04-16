1class Solution {
2public:
3
4    bool solve(int n,int k){
5        //sum till k
6        int sum1=((k)*(k+1))/2;
7        int sum2=((n)*(n+1))/2;
8        int sum3=sum2-sum1+k;
9
10        return sum1==sum3;
11    }
12
13    int pivotInteger(int n) {
14        //calculating from n to 0
15        for(int i=n;i>=0;i--){
16            if(solve(n,i)){
17                return i;
18            }
19        }
20        return -1;
21    }
22};