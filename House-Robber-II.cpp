class Solution {
public:

    int solve1(vector<int>&v,int ind,vector<int>&dp1){
        if(ind>=v.size()-1){
            return 0;
        }
        if(dp1[ind]!=-1){
            return dp1[ind];
        }
        //take case
        int take=v[ind]+solve1(v,ind+2,dp1);

        //not take case
        int nottake=solve1(v,ind+1,dp1);


        return dp1[ind]=max(take,nottake);
    }


    int solve2(vector<int>&v,int ind,vector<int>&dp2){
        if(ind>=v.size()){
            return 0;
        }
        if(dp2[ind]!=-1){
            return dp2[ind];
        }
        //take case
        int take=v[ind]+solve2(v,ind+2,dp2);

        //not take case
        int nottake=solve2(v,ind+1,dp2);


        return dp2[ind]=max(take,nottake);
    }

    int rob(vector<int>& v) {
        int n=v.size();

        if(n==1){
            return v[0];
        }

        vector<int>dp1(101,-1);
        vector<int>dp2(101,-1);

        int ans1=solve1(v,0,dp1);
        int ans2=solve2(v,1,dp2);


        return max(ans1,ans2);
    }
};