class Solution {
public:
    int firstStableIndex(vector<int>& v, int k) {
        //looks like a very easy problem to me
        int n=v.size();
        vector<int>miniv(n,v[0]);
        vector<int>maxiv(n,v[0]);
        int maxi=v[0];
        int mini=v[n-1];
        for(int i=1;i<n;i++){
            maxi=max(maxi,v[i]);
            maxiv[i]=maxi;
        }
        for(int i=n-1;i>=0;i--){
            mini=min(mini,v[i]);
            miniv[i]=mini;
        }

        for(int i=0;i<n;i++){
            if(maxiv[i]-miniv[i]<=k){
                return i;
            }
        }
        return -1;
    }
};