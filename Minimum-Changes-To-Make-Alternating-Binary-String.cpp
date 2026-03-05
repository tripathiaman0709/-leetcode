1class Solution {
2public:
3    int minOperations(string s) {
4        int n=s.size();
5        //do hi strings possible hai 
6        //one is starting from zero
7        //and other is starting from one
8        //as alternating hai
9        string one="";
10        string zero="";
11
12        for(int i=0;i<n;i++){
13            one+='0';
14        }
15        for(int i=0;i<n;i++){
16            zero+='0';
17        }
18
19        for(int i=1;i<n;i+=2){
20            zero[i]='1';
21        }
22
23        for(int i=0;i<n;i+=2){
24            one[i]='1';
25        }
26
27        int diff1=0;
28        int diff2=0;
29
30        for(int i=0;i<n;i++){
31            if(s[i]!=one[i]){
32                diff1++;
33            }
34        }
35
36        for(int i=0;i<n;i++){
37            if(s[i]!=zero[i]){
38                diff2++;
39            }
40        }
41
42        int ans=min(diff1,diff2);
43
44        return ans;
45    }
46};