class Solution {
public:

    int solve(int ind,vector<pair<int,int>>&v,int n,int m,int z,int o,vector<vector<vector<int>>>&dp){
        if(ind>=v.size()){
            return 0;
        }
        if(dp[ind][z][o]!=-1){
            return dp[ind][z][o];
        }
        int zero=v[ind].first;
        int one=v[ind].second;
        int pick=0;
        if(z+zero<=n && o+one<=m){
            pick=1+solve(ind+1,v,n,m,z+zero,o+one,dp);
        }
        int notpick=solve(ind+1,v,n,m,z,o,dp);

        return dp[ind][z][o]=max(pick,notpick);
    }

    int findMaxForm(vector<string>& v, int n, int m) {
        vector<pair<int,int>>vec;
        int sz=v.size();
        for(int i=0;i<sz;i++){
            int count0=0;
            int count1=0;
            string s=v[i];
            for(int i=0;i<s.size();i++){
                if(s[i]=='0'){
                    count0++;
                }else{
                    count1++;
                }
            }
            vec.push_back({count0,count1});
        }

        // sort(vec.begin(),vec.end());

        //now using sliding window

        // int l=0;
        // int r=0;
        // int zero=0;
        // int one =0;
        // int ans=0;
        // while(r<sz){
        //     zero+=vec[r].first;
        //     one+=vec[r].second;

        //     if(zero<=n && one<=m){
        //         ans=max(ans,r-l+1);
        //     }
        //     else{
        //         zero-=vec[l].first;
        //         one-=vec[l].second;
        //         l++;
        //     }

        //     r++;
        // }

        // return ans;


        //pick or not pick dp

        vector<vector<vector<int>>>dp(sz+1,vector<vector<int>>(n+1,vector<int>(m+1,-1)));

        int ans=0;
        
        ans=max(ans,solve(0,vec,n,m,0,0,dp));

        return ans;
    }
};