1class Solution {
2public:
3    int maxRotateFunction(vector<int>& v) {
4        //firstly trying brute force approach
5        int n=v.size();
6        // for(int x=0;x<n;x++){
7        //     int sum=0;
8        //     for(int i=0;i<n;i++){
9        //         sum+=(v[i]*((i+x)%n));
10        //     }
11        //     ans=max(ans,sum);
12        // }
13
14        //as this O(n^2) approach gave tle so optimizing it
15
16        int sum=0;
17        int total=0;
18        for(int i=0;i<n;i++){
19            sum+=(v[i]*i);
20            total+=v[i];
21        }
22
23        int ans=sum;
24        for(int i=0;i<n;i++){
25            int val=sum+total-(n*v[n-i-1]);
26            ans=max(ans,val);
27            sum=val;
28        }
29        return ans;
30    }
31};