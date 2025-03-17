class Solution {
public:
    bool divideArray(vector<int>& v) {
        int n=v.size();
        // unordered_map<int,int>mpp;
        // for(auto it:v){
        //     mpp[it]++;
        // }
        // int ans=0;
        // for(auto it:mpp){
        //     if(it.second%2!=0){
        //         return false;
        //     }
        // }
        // return true;
        sort(v.begin(),v.end());
        for(int i=0;i<n;i+=2){
            if(v[i]!=v[i+1]){
                return false;
            }
        }
        return true;
    }
};