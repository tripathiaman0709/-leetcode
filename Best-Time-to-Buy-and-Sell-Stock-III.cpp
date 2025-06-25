class Solution {
public:
    
    int profit=0;
    vector<vector<vector<int>>>dp;

    int fun(vector<int>&v,int ind,int buy,int limit){
        if(ind>=v.size() || limit<=0){
            return 0;
        }
        if(dp[ind][buy][limit]!=-1){
            return dp[ind][buy][limit];//already calculated
        }
        
        if(buy==1){
            profit=max(-v[ind]+fun(v,ind+1,0,limit),fun(v,ind+1,1,limit));
        }else{
            profit=max(v[ind]+fun(v,ind+1,1,limit-1),fun(v,ind+1,0,limit));
        }

        return dp[ind][buy][limit]=profit;
    }

    int maxProfit(vector<int>& v) {
        int n=v.size();
        dp=vector<vector<vector<int>>>(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return fun(v,0,1,2);
    }
};