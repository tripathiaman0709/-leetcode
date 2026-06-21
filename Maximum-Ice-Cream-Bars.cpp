1class Solution {
2public:
3    int maxIceCream(vector<int>& v, int k) {
4        int n=v.size();
5        sort(v.begin(),v.end());
6        int ans=0;
7        for(auto it:v){
8            k-=it;
9            if(k>=0)ans++;
10            else break;
11        }
12
13        return ans;
14    }
15};