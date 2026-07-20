class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int total =0 ;
        for(int i =0 ;i<32 ;i++){
            int cntSet =0;
            for(auto e : nums){
                if((e>>i)&1)cntSet++;
            }
            int cntUnset = nums.size()-cntSet;
            total+=cntSet*cntUnset;
        }
        return total;
    }

    //O(N^2) approach
    //  int totalHammingDistance(vector<int>& nums) {
    //     int cnt =0;
    //     for(int i =0 ;i<nums.size()-1;i++){
    //         for(int j =i+1; j<nums.size();j++){
    //             int xorr =nums[i]^nums[j]; 
    //             cnt+= __builtin_popcount(xorr);
    //         }
    //     }
    //     return cnt;
    // }
};