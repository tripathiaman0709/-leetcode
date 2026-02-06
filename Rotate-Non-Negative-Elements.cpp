1class Solution {
2public:
3    vector<int> rotateElements(vector<int>& v, int k) {
4        int n=v.size();
5        vector<int>pos;
6        for(int i=0;i<n;i++){
7            if(v[i]>=0){
8                pos.push_back(v[i]);
9            }
10        }
11        if(pos.size()==0 || k==0){
12            return v;
13        }
14        int sz=pos.size();
15        k%=sz;
16        vector<int>vec(sz,0);
17        for(int i=0;i<sz;i++){
18            int mod=((i+k+sz))%sz;
19            vec[i]=pos[(mod)];
20        }
21        int start=0;
22        for(int i=0;i<n;i++){
23            if(v[i]<0){
24                continue;
25            }else{
26                v[i]=vec[start++];
27            }
28        }
29        return v;
30    }
31};