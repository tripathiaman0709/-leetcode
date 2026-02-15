1class Solution {
2public:
3    vector<int> toggleLightBulbs(vector<int>& v) {
4        int n=v.size();
5        vector<int>ans;
6        vector<int>bulb(101,0);
7        for(int i=0;i<n;i++){
8            bulb[v[i]]++;
9        }
10        for(int i=0;i<101;i++){
11            if(bulb[i]%2){
12                ans.push_back(i);
13            }
14        }
15        return ans;
16    }
17};