1class Solution {
2public:
3    long long minimumCost(int ic1, int ic2, int ic3, int in1, int in2) {
4        long long c1=ic1;
5        long long c2=ic2;
6        long long c3=ic3;
7        long long n1=in1;
8        long long n2=in2;
9        
10        long long ans=0;
11        long long atleast=min(n1,n2);
12        if(c3<=c2+c1){
13            n1-=atleast;
14            n2-=atleast;
15
16            ans+=(atleast*c3);
17        }
18
19        if(c1>=c3){
20            ans+=(c3*n1);
21            n2-=n1;
22            n1=0;
23        }
24        if(c2>=c3 && n2>0){
25            ans+=(c3*n2);
26            n1-=n2;
27            n2=0;
28        }
29
30        if(n1>0){
31            long long v1=c1*n1;
32            long long v2=c3*n1;
33
34            if(v1<v2){
35                ans+=v1;
36            }else{
37                ans+=v2;
38            }
39        }
40        if(n2>0){
41            long long v1=c2*n2;
42            long long v2=c3*n2;
43
44            if(v1<v2){
45                ans+=v1;
46            }else{
47                ans+=v2;
48            }
49        }
50
51        return ans;
52    }
53};