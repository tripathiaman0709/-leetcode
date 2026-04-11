1class Solution {
2public:
3
4    int solve(int num,int k){
5        int total=0;
6        while(num){
7            if(num%10==k)total++;
8            num/=10;
9        }
10        return total;
11    }
12
13    int countDigitOccurrences(vector<int>& v, int k) {
14        //easy question
15        int n=v.size();
16        int sum=0;
17        for(int i=0;i<n;i++){
18            sum+=solve(v[i],k);
19        }
20        return sum;
21    }
22};