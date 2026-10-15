class Solution {
public:
    int sumCounts(vector<int>& v) {
        int n=v.size();
        //making all the possible subarrays
        //then storing it in unordered set then simply counting the square of size of set
        int ans=0;
        for(int i=0;i<n;i++){
            unordered_set<int>st;
            for(int j=i;j<n;j++){
                st.insert(v[j]);
                int sz=st.size();
                // cout<<sz<<' ';
                ans+=(sz*sz);
            }
        }
        return ans;
    }
};