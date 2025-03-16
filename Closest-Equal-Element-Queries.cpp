class Solution {
public: 
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        vector<int> ans(queries.size(),-1);
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
        }
        int sz=nums.size();
        for(int i=0;i<queries.size();i++){
            int n=nums[queries[i]];
            if(mp[n].size()<2)continue;
            auto it = lower_bound(mp[n].begin(), mp[n].end(), queries[i]);
            int t=mp[n].size();
            int cur=it-mp[n].begin();
            int x=mp[n][(cur-1+t)%t];
            int y=mp[n][(cur+1)%t];
            int z=mp[n][cur];
            int dist1=min((z-x+sz)%sz,(x-z+sz)%sz), dist2=min((z-y+sz)%sz,(y-z+sz)%sz);
            ans[i]=min(dist1,dist2);
        }
        return ans;
    }
};