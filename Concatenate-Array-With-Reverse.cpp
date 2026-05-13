1class Solution {
2public:
3    vector<int> concatWithReverse(vector<int>& v) {
4        vector<int>ans=v;
5        for(int i=v.size()-1;i>=0;i--){
6            ans.push_back(v[i]);
7        }
8
9        return ans;
10    }
11};