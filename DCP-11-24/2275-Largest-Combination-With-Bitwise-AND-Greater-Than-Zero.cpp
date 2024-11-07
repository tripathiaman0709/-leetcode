class Solution {
public:
    int largestCombination(vector<int>& v) {
        int count=0;
        int maxi=0;
        //TC=O(n)
        //SC=O(1)
        for(int i=0;i<24;i++){
            count=0;
            for(int j=0;j<v.size();j++){
                if(v[j]&(1<<i)){
                    count++;
                }
            }
            maxi=max(maxi,count);
        }
        return maxi;
    }
};