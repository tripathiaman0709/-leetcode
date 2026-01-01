1class Solution {
2public:
3    vector<int> plusOne(vector<int>& a) {
4        int n=a.size();
5        for(int i=n-1;i>=0;i--){
6            if(a[i]==9){
7                a[i]=0;
8            }else{
9                a[i]=a[i]+1;
10                break;
11            }
12        }
13        
14        if(a[0]==0){
15            vector<int>v(n+1);
16            v[0]=1;
17        for(int i=0;i<n;i++){
18            v[i+1]=a[i];
19        }
20        return v;
21        }else{
22            vector<int>v(n);
23            for(int i=0;i<n;i++){
24                v[i]=a[i];
25            }
26            return v;
27        }
28        
29    }
30};