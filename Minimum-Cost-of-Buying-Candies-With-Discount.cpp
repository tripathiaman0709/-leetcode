1class Solution {
2public:
3    int minimumCost(vector<int>& v) {
4        int n=v.size();
5        sort(v.rbegin(),v.rend());
6        int sum=0;
7        int ind=0;
8        while(ind<n){
9            if(ind+1>=n && ind<n){
10                sum+=v[ind];
11            }
12            if(ind+1>=n){
13                break;
14            }
15            sum+=v[ind]+v[ind+1];
16            ind+=3;
17        }
18
19        return sum;
20    }
21};