1class Solution {
2public:
3    long long maximumHappinessSum(vector<int>& v, int k) {
4        int n=v.size();
5        long long sum=0;
6        long long count=0;
7        sort(v.rbegin(),v.rend());
8        for(int i=0;i<k;i++){
9            if(v[i]-count<=0){
10                break;
11            }
12            sum+=(v[i]-count);
13            count++;
14        }
15        return sum;
16    }
17};