1class Solution {
2public:
3
4    int solve(string s){
5        int n=s.size();
6        int ans=0;
7        for(int i=0;i<n;i++){
8            if(s[i]=='1') ans+=pow(2,i);
9        }
10        return ans;
11    }
12
13    string binary(int n){
14        string s="";
15        while(n){
16            if(n%2)s+='1';
17            else s+='0';
18            n/=2;
19        }
20        return s;
21    }
22
23    int bitwiseComplement(int n) {
24        if(n==0){
25            return 1;
26        }
27        
28        string s=binary(n);
29        int sz=s.size();
30        string ans="";
31        for(int i=0;i<sz;i++){
32            if(s[i]=='0'){
33                ans+='1';
34            }else{
35                ans+='0';
36            }
37        }
38
39        return solve(ans);
40    }
41};