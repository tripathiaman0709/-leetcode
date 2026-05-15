1class Solution {
2public:
3    int findMin(vector<int>& a) {
4        int n=a.size();
5        int low=0;
6        int high=n-1;
7        while(low<high){
8            if(a[low]<a[high]){
9                return a[low];
10            }else{
11                int mid=low+(high-low)/2;
12                if(a[mid]>=a[low]){
13                    low=mid+1;
14                }else{
15                    high=mid;
16                }
17            }
18        }
19        return a[low];
20
21    }
22};