1class Solution {
2public:
3    vector<int> minBitwiseArray(vector<int>& v) {
4        int n=v.size();
5        vector<int>final;
6        for(int i=0;i<n;i++){
7            int val=v[i];
8            int ans=-1;
9            for(int j=0;j<1001;j++){
10
11                int a=j;
12                if(a>val){
13                    break;
14                }
15                int b=j+1;
16                int x=a|b;
17                if(x==val){
18                    ans=j;
19                    break;                    
20                }
21            }
22            final.push_back(ans);
23        }
24        return final;
25    }
26};