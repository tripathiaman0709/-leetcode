1class Solution {
2public:
3    vector<int> countOppositeParity(vector<int>& v) {
4        int n=v.size();
5        vector<int>ans(n,0);
6
7        for(int i=0;i<n-1;i++){
8            int count=0;
9            int parity=v[i]%2;
10            for(int j=i+1;j<n;j++){
11                int nparity=v[j]%2;
12                if(parity!=nparity)count++;
13            }
14            ans[i]=count;
15        }
16
17        return ans;
18    }
19};