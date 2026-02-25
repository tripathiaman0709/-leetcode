1class Solution {
2public:
3
4    int fact(int n){
5        if(n==0) return 1;
6        int pro=1;
7        for(int i=1;i<=n;i++){
8            pro*=i;
9        }
10        return pro;
11    }
12
13    bool isDigitorialPermutation(int n) {
14        int sum=0;
15        vector<int>v1;
16        vector<int>v2;
17
18        while(n){
19            sum+=fact(n%10);
20            v1.push_back(n%10);
21            n/=10;
22        }        
23
24        while(sum){
25            v2.push_back(sum%10);
26            sum/=10;
27        }
28
29        if(v1.size()!=v2.size()){
30            return false;
31        }
32
33        sort(v1.begin(),v1.end());
34        sort(v2.begin(),v2.end());
35
36        
37        for(int i=0;i<v1.size();i++){
38            if(v1[i]!=v2[i]) return false;
39        }
40
41        return true;
42    }
43};