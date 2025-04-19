class Solution {
public:
    long long countFairPairs(vector<int>& v, int l, int u) {
        //looks like gotta use binary search's lower bound and upper bound functions

        //but firstly trying simple brute force approach

        // int n=v.size();
        // int count=0;
        // for(int i=0;i<n-1;i++){
        //     for(int j=i+1;j<n;j++){
        //         if(v[i]+v[j]>=l && v[i]+v[j]<=u){
        //             count++;
        //         }
        //     }
        // }
        // return count;

        //O(n^2) approch wouldn't work

        int n=v.size();
        sort(v.begin(), v.end());
        long long ans=0;
        for(int i=0;i<n-1;i++){
            int lower=lower_bound(v.begin()+i+1,v.end(),l-v[i])-(v.begin());
            int upper=upper_bound(v.begin()+i+1,v.end(),u-v[i])-(v.begin());

            ans+=(upper-lower);
        }
        return ans;
    }
};