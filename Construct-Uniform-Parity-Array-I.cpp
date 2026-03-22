1class Solution {
2public:
3    bool uniformArray(vector<int>& v) {
4        int n=v.size();
5        //sbko even banao
6        bool even=true;
7        bool odd=true;
8        for(int i=0;i<n;i++){
9            if(v[i]%2){
10                bool billu=false;
11                for(int j=0;j<n;j++){
12                    if(v[i]==v[j])continue;
13
14                    if(v[j]-v[i]>=1 && ((v[j]-v[i])%2)==0){
15                        billu=true;
16                    }
17                }
18                if(billu=false){
19                    even=false;
20                }
21            }
22        }
23
24        for(int i=0;i<n;i++){
25            if(v[i]%2==0){
26                bool billu=false;
27                for(int j=0;j<n;j++){
28                    if(v[i]==v[j])continue;
29
30                    if(v[j]-v[i]>=1 && ((v[j]-v[i])%2)==1){
31                        billu=true;
32                    }
33                }
34                if(billu=false){
35                    odd=false;
36                }
37            }
38        }
39
40        if(odd==false && even==false)return false;
41        return true;
42    }
43};