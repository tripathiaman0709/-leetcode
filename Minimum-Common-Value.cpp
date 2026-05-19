1class Solution {
2public:
3    int getCommon(vector<int>& v1, vector<int>& v2) {
4        unordered_map<int,int>mpp;
5        for(auto it:v2){
6            mpp[it]++;
7        }
8        for(auto it:v1){
9            if(mpp[it]>0){
10                return it;
11            }
12        }
13
14        return -1;
15    }
16};