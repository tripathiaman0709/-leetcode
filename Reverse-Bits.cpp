1class Solution {
2public:
3
4    long long fun(string s){
5        long long n=s.size();
6        long long count=0;
7        long long sum=0;
8        for(long long i=n-1;i>=0;i--){
9            if(s[i]=='1'){
10                sum+=pow(2,count);
11            }
12            count++;
13        }
14        return sum;
15    }
16
17    string tobit(int n){
18        string ans="";
19        while(n){
20            if(n%2){
21                ans+='1';
22            }else{
23                ans+='0';
24            }
25            n/=2;
26        }
27        
28        reverse(ans.begin(),ans.end());
29
30        //padding extra zeros
31        int times=32-ans.size();
32
33        string add="";
34        for(int i=0;i<times;i++){
35            add+='0';
36        }
37        string final=add+ans;
38        return final;
39    }
40
41    int reverseBits(int n) {
42        string bit=tobit(n);
43        reverse(bit.begin(),bit.end());
44        long long num=fun(bit);
45
46        return (int)num;
47    }
48};