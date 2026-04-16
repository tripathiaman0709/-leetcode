1class Solution {
2public:
3    vector<int> solveQueries(vector<int>& vec, vector<int>& q) {
4        int n=vec.size();
5        vector<int>v;
6        for(auto it:vec){
7            v.push_back(it);
8        }
9        for(auto it:vec){
10            v.push_back(it);
11        }
12        for(auto it:vec){
13            v.push_back(it);
14        }
15
16        //using set
17        //but normal set and not unordered as we require the positions as well
18        set<pair<int,int>>st;
19        vector<int>ans;
20        for(int i=0;i<v.size();i++){
21            st.insert({v[i],i});
22        }
23        for(auto it:q){
24            int x=n+it;
25
26            auto pos=st.lower_bound({v[x],x});
27            int z=min({n,x-prev(pos)->second,next(pos)->second-x});
28            if(z<n){
29                ans.push_back(z);
30            }else{
31                ans.push_back(-1);
32            }
33        }
34        return ans;
35
36    }
37};