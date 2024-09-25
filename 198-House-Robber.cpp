class Solution {
public:
    int rob(vector<int>& a) {
        //maximum amount our boy could take away 
        //making sure that he cannot rob adjacent houses

        //tabulation --> bottom up approach
        //trying to calculate dp[n] by collecting data from earlier


        int n=a.size();
        vector<int>dp(n+1,-1);

        //defining state
        //dp[i]=maximum steal uptil i
        dp[0]=0;
        dp[1]=a[0];

        for(int i=2;i<=n;i++){
            dp[i]=max(dp[i-1],a[i-1]+dp[i-2]);
        }
        int ans=dp[n];
        return ans;
    }
};