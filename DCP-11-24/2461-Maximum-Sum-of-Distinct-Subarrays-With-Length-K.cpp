class Solution {
public:
    long long maximumSubarraySum(vector<int>& v, int k) {
        //using sliding window technique

        int n=v.size();
        int l=0;
        int r=0;
        long long sum=0;
        long long maxi=0;
        unordered_set<int>st;
        while(r<n){
            while(st.count(v[r])){
                st.erase(v[l]);
                sum-=v[l];
                l++;
            }

            sum+=v[r];
            st.insert(v[r]);

            if(r-l+1==k){
                maxi=max(maxi,sum);
                st.erase(v[l]);
                sum-=v[l];
                l++;
            }
            r++;
        }
        return maxi;
    }
};