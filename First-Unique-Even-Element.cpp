1class Solution {
2public:
3    int firstUniqueEven(vector<int>& v) {
4        int n=v.size();
5        
6        unordered_map<int,int>mpp;
7        for(int i=0;i<n;i++){
8            mpp[v[i]]++;
9        }
10        for(int i=0;i<n;i++){
11            if(v[i]%2==0 && mpp[v[i]]==1){
12                return v[i];
13            }
14        }
15        return -1;
16    }
17};