1class Solution {
2public:
3    vector<int> minCost(vector<int>& v, vector<vector<int>>& q) {
4        int n=v.size();
5        vector<int>rtol(n,0);
6        vector<int>ltor(n,0);
7
8        for(int i=0;i<n-1;i++){
9            if(i==0 || (v[i+1]-v[i] < v[i]-v[i-1])){
10                rtol[i]=1;
11            }else{
12                rtol[i]=v[i+1]-v[i];
13            }
14        }
15
16        for(int i=1;i<n;i++){
17            if(i==n-1 || (v[i]-v[i-1] <= v[i+1]-v[i])){
18                ltor[i]=1;
19            }else{
20                ltor[i]=v[i]-v[i-1];
21            }
22        }
23
24        vector<int>prertol(n,0);
25        vector<int>preltor(n,0);
26
27        for(int i=1;i<n;i++){
28            prertol[i]=prertol[i-1]+rtol[i-1];
29        }
30        for(int i=1;i<n;i++){
31            preltor[i]=preltor[i-1]+ltor[i];
32        }
33
34        vector<int>ans;
35        for(int i=0;i<q.size();i++){
36            int l=q[i][0];
37            int r=q[i][1];
38
39            if(l==r)ans.push_back(0);
40            if(l>r)ans.push_back(preltor[l]-preltor[r]);
41            if(l<r)ans.push_back(prertol[r]-prertol[l]);
42        }
43        return ans;
44    }
45};