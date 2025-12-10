1class Solution {
2public:
3    int M=1e9+7;
4    int fact(int n){
5        long long val=1;
6        for(int i=n;i>=2;i--){
7            val=(val*i)%M;
8        }
9        return val;
10    }
11    int countPermutations(vector<int>& v) {
12        int start=v[0];
13        sort(v.begin(),v.end());
14        int n=v.size();
15        int count=0;
16        for(auto it:v){
17            if(start==it){
18                count++;
19            }
20        }
21        if(count>1 || start!=v[0]){
22            return 0;
23        }
24
25        long long ans=fact(n-1);
26        return int(ans);
27    }
28};  