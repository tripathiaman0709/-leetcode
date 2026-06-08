1class Solution {
2public:
3    vector<int> pivotArray(vector<int>& v, int k) {
4        vector<int>less;
5        vector<int>equal;
6        vector<int>more;
7
8        int n=v.size();
9
10        for(int i=0;i<n;i++){
11            if(v[i]==k){
12                equal.push_back(v[i]);
13            }else if(v[i]<k){
14                less.push_back(v[i]);
15            }else{
16                more.push_back(v[i]);
17            }
18        }
19
20        vector<int>ans;
21
22        for(auto it:less){
23            ans.push_back(it);
24        }
25        for(auto it:equal){
26            ans.push_back(it);
27        }
28        for(auto it:more){
29            ans.push_back(it);
30        }
31
32        return ans;
33    }
34};