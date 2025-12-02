1class Solution {
2public:
3    int countElements(vector<int>& v, int k) {
4        int n=v.size();
5        vector<int>vec;
6        for(int i=0;i<n;i++){
7            vec.push_back(v[i]);
8        }
9        sort(vec.begin(),vec.end());
10
11        int ans=0;
12        for(int i=0;i<n;i++){
13            auto it=upper_bound(vec.begin(),vec.end(),v[i]);
14            int num = vec.end() - it;  
15            if(num>=k){
16                ans++;
17            }
18        }
19        return ans;
20    }
21};