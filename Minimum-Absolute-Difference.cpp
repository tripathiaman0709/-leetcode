1class Solution {
2public:
3    vector<vector<int>> minimumAbsDifference(vector<int>& v) {
4        int n=v.size();
5        int mini=INT_MAX;
6        sort(v.begin(),v.end());
7
8        for(int i=0;i<n-1;i++){
9            mini=min(abs(v[i]-v[i+1]),mini);
10        }
11        vector<vector<int>>ans;
12        for(int i=0;i<n-1;i++){
13            if(v[i+1]-v[i]==mini){
14                vector<int>temp;
15                temp.push_back(v[i]);
16                temp.push_back(v[i+1]);
17                ans.push_back(temp);
18            }
19        }
20        // sort(ans.begin(),ans.end());
21        return ans;
22        
23    }
24};