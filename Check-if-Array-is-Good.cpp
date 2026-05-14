1class Solution {
2public:
3    bool isGood(vector<int>& v) {
4        int n=v.size();
5        sort(v.begin(),v.end());
6        for(int i=0;i<n-1;i++){
7            if(v[i]!=i+1){
8                return false;
9            }
10        }
11        if(v[n-1]!=n-1)return false;
12        
13        return true;
14    }
15};