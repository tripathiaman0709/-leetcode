class Solution {
public:
    
    long long solve(vector<vector<int>>&v,int ind,vector<long long>&dp){
        if(ind>=v.size()){
            return 0;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        //take case
        long long take=v[ind][0]+solve(v,ind+v[ind][1]+1,dp);
        //not take case
        long long nottake=solve(v,ind+1,dp);

        return dp[ind]=max(take,nottake);
    }

    long long mostPoints(vector<vector<int>>& v) {
        //i think we would use a pick and not pick dp 
        //firstly writing a recursion code

        //now using memoization
        vector<long long>dp(100001,-1);

        return solve(v,0,dp);

        //now tc is O(n);

        //ie->O(10^5)


    }
};