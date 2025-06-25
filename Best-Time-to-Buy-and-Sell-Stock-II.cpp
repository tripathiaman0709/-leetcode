class Solution {
public:

    int profit=0;
    vector<vector<int>>dp;
    
    int fun(vector<int>& v,int ind,int buy){
        
        if(ind>v.size()-1){
            return 0;
        }       
        if(dp[ind][buy]!=-1){
            return dp[ind][buy];
        } 

        if(buy){
            profit=max(-v[ind]+fun(v,ind+1,0),fun(v,ind+1,1));
        }else{
            profit=max(v[ind]+fun(v,ind+1,1),fun(v,ind+1,0));
        }

        return dp[ind][buy]=profit;
    }

    int maxProfit(vector<int>& v) {
        
        //bass ab dp lagegi
        dp=vector<vector<int>>(v.size()+1, vector<int>(2, -1));
        return fun(v,0,1);
        
    }
};