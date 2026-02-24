1class Solution {
2public:
3
4    string solve(int n){
5        string s="";
6        while(n){
7            if(n%2){
8                s+='1';
9            }else{
10                s+='0';
11            }
12            n/=2;
13        }
14        reverse(s.begin(),s.end());
15        return s;
16    }
17
18    int binaryGap(int n) {
19        string s=solve(n);
20
21        int sz=s.size();
22        int prev=-1;
23        int next=-1;
24
25        int maxi=0;
26        for(int i=0;i<sz;i++){
27            if(s[i]=='1' && prev==-1){
28                prev=i;
29            }
30            if(s[i]=='1' && prev!=-1){
31                next=i;
32                maxi=max(maxi,next-prev);
33                prev=next;
34            }
35        }
36        return maxi;
37    }
38};