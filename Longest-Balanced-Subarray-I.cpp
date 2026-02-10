1class Solution {
2public:
3    int longestBalanced(vector<int>& v) {
4        int n=v.size();
5        //firstly doing brute force approach
6        //O(n^2) approach
7
8        int ans=0;
9
10        for(int i=0;i<n;i++){
11            unordered_set<int>odd;
12            unordered_set<int>even;
13            for(int j=i;j<n;j++){
14                if(v[j]%2){
15                    odd.insert(v[j]);
16                }else{
17                    even.insert(v[j]);
18                }
19
20                if(odd.size()==even.size()){
21                    ans=max(ans,j-i+1);
22                }
23            }
24        }
25
26        return ans;
27    }
28};
29