1class Solution {
2public:
3    int minAbsoluteDifference(vector<int>& v) {
4        int n=v.size();
5        int mini=101;
6        for(int i=0;i<n;i++){
7            for(int j=0;j<n;j++){
8                if(i==j) continue;
9                if(v[i]==1 && v[j]==2){
10                    mini=min(mini,abs(i-j));
11                }
12            }
13        }
14        if(mini==101){
15            return -1;
16        }
17        return mini;
18    }
19};