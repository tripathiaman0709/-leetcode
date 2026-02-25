1class Solution {
2public:
3
4    int setbits(int n){
5        int count=0;
6        while(n){
7            if(n%2){
8                count++;
9            }
10            n/=2;
11        }
12        return count;
13    }
14
15    vector<int> sortByBits(vector<int>& v) {
16        int n=v.size();
17        vector<int>ans;
18        map<int,vector<int>>mpp;
19        for(int i=0;i<n;i++){
20            int x=setbits(v[i]);
21            mpp[x].push_back(v[i]);
22        }
23
24        for(auto it:mpp){
25            vector<int>vec=it.second;
26            sort(vec.begin(),vec.end());
27            for(auto x:vec){
28                ans.push_back(x);
29            }
30        }
31        return ans;
32    }
33};