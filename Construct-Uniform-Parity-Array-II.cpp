1class Solution {
2public:
3    bool uniformArray(vector<int>& nums1) {
4        int n = nums1.size();
5        int cnteve=0; int cntodd=0;
6        for(auto x:nums1){
7            if(x%2==0) cnteve++;
8            else cntodd++;
9        }
10
11        //if all even or all odd return true
12        if(cnteve == n || cntodd == n) return true; 
13
14
15        //if mix of even and odd -> We can only make even num as odd by substracting with odd
16
17        int mn=1e9+1;
18        for(auto x:nums1){
19            if(x%2==1) mn = min(mn,x);
20        }
21
22        for(auto x:nums1){
23            if(x%2==0 && x-mn<1) return false;
24        }
25        return true;
26    }
27};