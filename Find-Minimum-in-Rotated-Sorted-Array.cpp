1class Solution {
2public:
3
4    int findMin(vector<int>& v) {
5
6        int low = 0;
7        int high = v.size() - 1;
8
9        while(low < high){
10
11            int mid = low + (high - low) / 2;
12
13            if(v[mid] > v[high]){
14
15                low = mid + 1;
16
17            }else{
18
19                high = mid;
20            }
21        }
22
23        return v[low];
24    }
25};