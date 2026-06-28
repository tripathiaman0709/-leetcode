1class Solution {
2public:
3    int maximumElementAfterDecrementingAndRearranging(vector<int>& v) {
4        int n=v.size();
5        bool one=0;
6        sort(v.begin(),v.end());
7
8        if(v[0]==1){
9            one=1;
10        }
11
12        if(one){
13            for(int i=1;i<n;i++){
14                if(v[i]-v[i-1]>1){
15                    v[i]=v[i-1]+1;
16                }
17            }
18        }else{
19            v[0]=1;
20            for(int i=1;i<n;i++){
21                if(v[i]-v[i-1]>1){
22                    v[i]=v[i-1]+1;
23                }
24            }
25        }
26
27        int maxi=1;
28        for(auto it:v){
29            maxi=max(maxi,it);
30        }
31
32        return maxi;
33    }
34};