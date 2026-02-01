1class Solution {
2public:
3    int minimumCost(vector<int>& v) {
4        int n=v.size();
5
6        int sum=v[0];
7        int smallest=1000;
8        int secondsmallest=1000;
9        int ind=0;
10        for(int i=1;i<n;i++){
11            if(v[i]<=smallest){
12                smallest=v[i];
13                ind=i;
14            }
15        }
16        for(int i=1;i<n;i++){
17            if(v[i]<=secondsmallest && ind!=i){
18                secondsmallest=v[i];
19            }
20        }
21
22        sum+=smallest;
23        sum+=secondsmallest;
24
25        return sum;
26    }
27};