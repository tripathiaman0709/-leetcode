class Solution {
public:
    bool divideArray(vector<int>& v) {
        int n=v.size();
        unordered_map<int,int>mpp;
        for(auto it:v){
            mpp[it]++;
        }
        int ans=0;
        for(auto it:mpp){
            if(it.second%2!=0){
                return false;
            }
        }
        return true;
    }
};