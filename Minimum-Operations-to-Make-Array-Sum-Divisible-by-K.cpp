class Solution {
public:
    int minOperations(vector<int>& v, int k) {
        int sum=0;
        for(auto it:v){
            sum+=it;
        }
        int ans=sum%k;
        return ans;
    }
};