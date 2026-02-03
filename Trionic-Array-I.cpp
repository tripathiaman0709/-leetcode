1class Solution {
2public:
3    bool isTrionic(vector<int>& v) {
4        int n=v.size();
5        int p=0;
6        int q=0;
7        for(int i=0;i<n-1;i++){
8            if(v[i]==v[i+1]){
9                return false;
10            }
11        }
12        for(int i=0;i<n-1;i++){
13            if(v[i]>v[i+1]){
14                p=i;
15                break;
16            }
17        }
18        for(int i=p;i<n-1;i++){
19            if(v[i]<v[i+1]){
20                q=i;
21                break;
22            }
23        }
24        for(int i=q;i<n-1;i++){
25            if(v[i]>v[i+1]){
26                return false;
27            }
28        }
29        if(p==0 || p==q){
30            return false;
31        }
32        return true;
33    }
34};