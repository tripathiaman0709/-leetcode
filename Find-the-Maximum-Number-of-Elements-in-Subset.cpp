1class Solution {
2public:
3    int maximumLength(vector<int>&nums) {
4        unordered_map<int,int>mp;
5        for(int x:nums)mp[x]++;
6        int ans=1;
7
8        for(int i=0;i<nums.size();i++){
9            int x=nums[i];
10            if(x==1){
11                if(mp[x]%2!=0)ans=max(ans,mp[x]);
12                else ans=max(ans,mp[x]-1);
13            }
14            else{
15                int ct=0;
16                if(mp[x]>=2){
17                    long long curr=x;
18                    while(curr<=INT_MAX && mp.find((int)curr)!=mp.end()){
19                        if(mp[(int)curr]==1){
20                            ct++;
21                            break;
22                        }
23                        ct++;
24                        if(curr>LLONG_MAX/curr)break;
25                        curr*=curr;
26                    }
27                }
28                ans=max(ans,ct*2-1);
29            }
30        }
31
32        return ans;
33    }
34};