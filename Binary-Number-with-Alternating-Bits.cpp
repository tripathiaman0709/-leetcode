1class Solution {
2public:
3
4bool solve(int n){
5    string ans="";
6    while(n){
7        if(n%2){
8            ans+='1';
9        }else{
10            ans+='0';
11        }
12        n/=2;
13    }
14
15    int sz=ans.size();
16    for(int i=0;i<sz-1;i++){
17        if(ans[i]==ans[i+1]){
18            return false;
19        }
20    }
21    return true;
22}
23
24    bool hasAlternatingBits(int n) {
25        return solve(n);
26        
27    }
28};