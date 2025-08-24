class Solution {
public:
    bool partitionArray(vector<int>& v, int k) {
        int n=v.size();  
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++){
            mpp[v[i]]++;
        }     
        for(auto it:mpp){
            if(it.second > n/k){
                return false;
            }
        }
        return !(n%k);
    }
};