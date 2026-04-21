1class Solution {
2public:
3    int singleNumber(vector<int>& v) {
4        int n=v.size();
5        //doing xor
6        int xoxo=0;
7        for(int i=0;i<n;i++){
8            xoxo^=v[i];
9        }
10
11        return xoxo;
12    }
13};