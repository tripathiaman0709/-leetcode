1class Solution {
2public:
3    bool asteroidsDestroyed(int m, vector<int>& v) {
4        int n=v.size();
5        sort(v.begin(),v.end());
6
7        //now after sorting in increasing order
8        long long x=m;
9
10        for(int i=0;i<n;i++){
11            if(x>=v[i]){
12                x+=v[i];
13            }else{
14                return false;
15            }
16        }
17        return true;
18    }
19};