1class Solution {
2public:
3    int findMin(vector<int>& v) {
4        int n=v.size();
5        int ansind=0;
6        int low=0;
7        int high=n-1;
8        
9        while(low+1<n && v[low]==v[low+1]){
10            low++;
11        }
12        while(high-1>=0 && v[high]==v[high-1]){
13            high--;
14        }
15
16        while(low<=high){
17            int mid=low+(high-low)/2;
18            if(v[mid]<v[ansind]){
19                ansind=mid;
20            }
21
22            if(v[mid]>v[high]){
23                //means rotated
24                low=mid+1;
25            }
26            else{
27                high=mid-1;
28            }
29        }
30
31        return v[ansind];
32    }
33};