class Solution {
public:
    int longestSubsequence(vector<int>& v) {
        
        int n=v.size();
        int val=0;
        long long sum=0;
        for(auto it:v){
            val^=it;
            sum+=it;
        }
        //edge case is that all elements are zero
        if(sum==0){
            return 0;
        }

        if(val==0){
            return n-1;
        }
        return n;
    }
};