class Solution {
public:
    int findLucky(vector<int>& v) {
        map<int,int>mpp;
        int n=v.size();
        for(int i=0;i<n;i++){
            mpp[v[i]]++;
        }
        int ans=-1;
        for(auto it:mpp){
            if(it.first==it.second){
                ans=it.first;
            }
        }

        return ans;
    }
};