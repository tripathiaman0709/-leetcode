1class Solution {
2public:
3
4    bool solve(vector<int>&v,int k){
5        int n=v.size();
6        //checking for value k
7        long long count=0;
8        for(int i=0;i<n;i++){
9            int factor=v[i]/k;
10            count+=factor;
11            if(v[i]%k){
12                count++;
13            }
14        }
15
16        //checking the given square case
17        long long sq=(long long)k*k;
18        if(count<=sq){
19            return true;
20        }
21        return false;
22    }
23
24    int minimumK(vector<int>& v) {
25        int n=v.size();
26        //this feels like a binary search on answer problem
27        int low=1;
28        int high=100000;
29        int ans=-1;
30        while(high>=low){
31            int mid=(low)+(high-low)/2;
32
33            if(solve(v,mid)){
34                ans=mid;
35                high=mid-1;
36            }else{
37                low=mid+1;
38            }
39        }
40
41        return ans;
42    }
43};