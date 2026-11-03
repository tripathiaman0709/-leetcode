class Solution {
public:
    int minMoves(vector<int>& v) {
        int n=v.size();
        int maxi=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,v[i]);
        }
        int ans=0;
        for(auto it:v){
            ans+=(maxi-it);
        }

        return ans;
    }
};