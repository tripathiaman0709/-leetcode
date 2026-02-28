1class Solution {
2public:
3
4    string solve(int n){
5        string ans="";
6        for(int i=1;i<=n;i++){
7            string s="";
8            int num=i;
9            while(num){
10                if(num%2)s+='1';
11                else s+='0';
12                num/=2;
13            }
14            reverse(s.begin(),s.end());
15            ans+=s;
16        }
17        return ans;
18    }
19
20    int fun(string s){
21        long long mod=1e9+7;
22        long long sum=0;
23        long long power=1;
24
25        for(int i=0;i<s.size();i++){
26            if(s[s.size()-1-i]=='1'){
27                sum=(sum+power)%mod;
28            }
29            power=(power*2)%mod;
30        }
31        return sum;
32    }
33
34    int concatenatedBinary(int n) {
35        string s=solve(n);
36        return fun(s);
37    }
38};