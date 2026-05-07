1/*
2// global static array option
3const int N=1e5;
4int prefMax[N], sufMin[N];
5*/
6class Solution {
7public:
8    static vector<int> maxValue(vector<int>& nums) {
9        const int n=nums.size();
10        vector<int> prefMax(n), sufMin(n);// vector option
11        prefMax[0]=nums[0];
12        sufMin[n-1]=nums[n-1];
13
14        for(int i=1; i<n; i++){
15            const int x=nums[i], y=nums[n-1-i];
16            prefMax[i]=max(prefMax[i-1], x);
17            sufMin[n-1-i]=min(sufMin[n-i], y);
18        }
19        vector<int> ans(n);
20        ans[n-1]=prefMax[n-1];
21        for(int i=n-2; i>=0; i--){
22            if (prefMax[i]>sufMin[i+1]) 
23                ans[i]=ans[i+1];
24            else ans[i]=prefMax[i];
25        }
26        return ans;
27    }
28};