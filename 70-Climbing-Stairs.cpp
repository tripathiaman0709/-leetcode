class Solution {
public:
    int climbStairs(int n) {
       int cur=1,prev=1,prev2 =1;
       for(int i=2;i<=n;i++){
        cur = prev+prev2;
        prev2 = prev;
        prev =cur;
       }
       return cur;
    }
};