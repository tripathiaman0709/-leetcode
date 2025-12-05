1class Solution {
2public:
3    int countPartitions(vector<int>& v) {
4        int n=v.size();
5
6        int sum=0;
7        for(auto it:v){
8            sum+=it;
9        }
10        int leftsum=v[0];
11        int ans=0;
12        for(int i=1;i<n;i++){
13            leftsum+=v[i];
14            int rightsum=sum-leftsum;
15            if((rightsum-leftsum)%2==0){
16                ans++;
17            }
18        }
19        return ans;
20    }
21};