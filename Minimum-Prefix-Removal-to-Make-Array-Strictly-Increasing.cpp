1class Solution {
2public:
3    int minimumPrefixLength(vector<int>& v) {
4        //so we need to find longest increasing subarray
5        int n=v.size();
6
7        vector<int>diff;
8        for(int i=0;i<n-1;i++){
9            diff.push_back(v[i+1]-v[i]);
10        }
11        int count=1;
12        for(int i=0;i<n-1;i++){
13            if(diff[i]>0){
14                count++;
15            }else{
16                count=1;
17            }
18        }
19        return n-count;
20    }
21};