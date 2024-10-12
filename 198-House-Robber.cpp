class Solution {
public:
    int rob(vector<int>& a) {
        //maximum amount our boy could take away 
        //making sure that he cannot rob adjacent houses

        //tabulation --> bottom up approach
        //trying to calculate dp[n] by collecting data from earlier

        //now constant space..


        int n=a.size();

        //defining state
        //dp[i]=maximum steal uptil i
        int pprev=0;
        int prev=a[0];

        for(int i=2;i<=n;i++){
            int cur=max(prev,a[i-1]+pprev);

            pprev=prev;
            prev=cur;
        }
        return prev;
    }
};