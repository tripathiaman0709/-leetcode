1 class Solution {
2public:
3    int maxPoints(vector<vector<int>>& pt) {
4        int ans=1; 
5        int n=pt.size();
6       // slope of every point with selected point
7        for(int i=0;i<n-1;i++){
8            unordered_map<double,int> mp;
9            for(int j=i+1;j<n;j++){
10                //calculating the slope
11                double x = (double)(pt[j][1]-pt[i][1])/(double)(pt[j][0]-pt[i][0]);
12                if((pt[j][0]-pt[i][0])==0 ) //infinite slope for Perpendicular line
13                mp[INT_MAX]++; 
14                else
15               //storing the slope into map
16                    mp[x]++;
17            }
18            // same slope w.r.t.that selected point
19            int temp = 0;
20            for(auto it:mp)
21                temp = max(temp, it.second+1);    // +1 for the current point(point itself)
22            ans = max(temp, ans);
23        }
24        return ans;
25    }
26};