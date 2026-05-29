1class Solution {
2public:
3    int getsum(int n){
4        int sum=0;
5        while(n){
6            sum+=n%10;
7            n/=10;
8        }
9        return sum;
10    }
11
12    int minElement(vector<int>& a) {
13        int n=a.size();
14        vector<int>v;
15        for(int i=0;i<n;i++){
16            v.push_back(getsum(a[i]));
17        }
18        sort(v.begin(),v.end());
19        int ans=v[0];
20        return ans;
21    }
22};