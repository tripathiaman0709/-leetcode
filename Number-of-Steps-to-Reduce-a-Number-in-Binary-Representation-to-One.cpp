1class Solution {
2public:
3
4    // int fun(string s){
5    //     reverse(s.begin(),s.end());
6    //     int n=s.size();
7    //     int val=0;
8    //     for(int i=0;i<n;i++){
9    //         if(s[i]=='1'){
10    //             val+=pow(2,i);
11    //         }
12    //     }
13    //     return val;
14    // }
15
16    int numSteps(string s) {
17        // int n=fun(s);
18        // int op=0;
19        // while(n>1){
20        //     if(n%2){
21        //         n++;
22        //     }else{
23        //         n/=2;
24        //     }
25        //     op++;
26        // }
27        // return op;
28        int op=0;
29        while(s!="1"){
30            if(s[s.size()-1]=='0'){
31                //even
32                string str=s.substr(0,s.size()-1);
33                s=str;
34            }else{
35                //odd
36                int count=0;
37                int sz=s.size();
38                for(int i=0;i<sz;i++){
39                    if(s[i]=='1')count++;
40                }
41                if(count==sz){
42                    string str="1";
43                    for(int i=0;i<sz;i++){
44                        str+="0";
45                    }
46                    s=str;
47                }else{
48                    for(int i=sz-1;i>=0;i--){
49                        if(s[i]=='0'){
50                            s[i]='1';
51                            break;
52                        }
53                    }
54                }
55            }
56            op++;
57        }
58        return op;
59    }
60};