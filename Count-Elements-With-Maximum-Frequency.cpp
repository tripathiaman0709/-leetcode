class Solution {
public:
    int maxFrequencyElements(vector<int>& v) {
        int n=v.size();
        // unordered_map<int,int>mp;
        vector<int>mp(101,0);
        for(auto it:v){
            mp[it]++;
        }
        int maxi=0;
        for(auto it:mp){
            maxi=max(maxi,it);
        }
        int ans=0;
        for(auto it:mp){
            if(it==maxi){
                ans+=it;
            }
        }
        return ans;
    }
};