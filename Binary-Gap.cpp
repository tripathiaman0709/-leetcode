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
22        vector<int>pos;
23        for(int i=0;i<sz;i++){
24            if(s[i]=='1') pos.push_back(i);
25        }
26        if(pos.size()<=1){
27            return 0;
28        }
29
30        //finding difference between two adj positions
31        int maxi=0;
32        for(int i=0;i<pos.size()-1;i++){
33            maxi=max(maxi,(pos[i+1]-pos[i]));
34        }
35
36        return maxi;
37    }
38};