class Solution {
public:
    long long countBadPairs(vector<int>& v) {
        int n=v.size();
        for(int i=0;i<n;i++){
            v[i]=v[i]-i;
        }
        unordered_map<int,int>mpp;
        mpp[v[0]]=1;
        long long ans=0;
        for(int i=1;i<n;i++){

            int pairspossible=i;
            int pairs=mpp[v[i]];
            ans+=(pairspossible-pairs);
            mpp[v[i]]++;

        }
        return ans;
    }
};