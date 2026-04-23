1class Solution {
2public:
3    int firstStableIndex(vector<int>& v, int k) {
4        //looks like a very easy problem to me
5        int n=v.size();
6        vector<int>miniv(n,v[0]);
7        vector<int>maxiv(n,v[0]);
8        int maxi=v[0];
9        int mini=v[n-1];
10        for(int i=1;i<n;i++){
11            maxi=max(maxi,v[i]);
12            maxiv[i]=maxi;
13        }
14        for(int i=n-1;i>=0;i--){
15            mini=min(mini,v[i]);
16            miniv[i]=mini;
17        }
18
19        for(int i=0;i<n;i++){
20            if(maxiv[i]-miniv[i]<=k){
21                return i;
22            }
23        }
24        return -1;
25    }
26};