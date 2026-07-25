class Solution {
public:

    void solve(int n,vector<int>&v){
        while(n){
            v.push_back(n%10);
            n/=10;
        }
    }

    int maxProduct(int n) {
        //finding two maximum digits of the number then numtiplying
        vector<int>digits;
        solve(n,digits);

        sort(digits.rbegin(),digits.rend());

        int ans=digits[0]*digits[1];

        return ans;
    }
};