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
        // sort(v.begin(),v.end());
        // for(int i=0;i<n;i+=2){
        //     if(v[i]!=v[i+1]){
        //         return false;
        //     }
        // }
        // return true;
        //using frequency vector of size 500
        vector<int>freq(501,0);
        for(int i=0;i<n;i++){
            freq[v[i]]++;
        }
        for(auto it:freq){
            if(it%2){
                return false;
            }
        }
        return true;
    }
};