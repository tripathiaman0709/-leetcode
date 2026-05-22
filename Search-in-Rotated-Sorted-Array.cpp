1class Solution {
2public:
3    int search(vector<int>& a, int target) {
4        int n=a.size();
5        int low=0;
6        int high=n-1;
7        while(low<=high){
8            int mid=low+(high-low)/2;
9            if(a[mid]==target){
10                return mid;
11            }
12            //checking whether left sorted 
13            if(a[mid]>=a[low]){
14                if(target>=a[low] && target<=a[mid]){
15                    high=mid-1;
16                }else{
17                    low=mid+1;
18                }
19            }else{
20                if(target>=a[mid] && target<=a[high]){
21                    low=mid+1;
22                }else{
23                    high=mid-1;
24                }
25            }
26        }
27        return -1;
28    }
29};