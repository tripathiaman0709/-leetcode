class Solution {
public:
    int minOperations(vector<int>& v, int k) {
        int n=v.size();
        unordered_set<int>st;
        for(auto it:v){
            st.insert(it);
        }

        int mini=INT_MAX;
        for(auto it:st){
            mini=min(mini,it);
        }

        if(mini<k){
            return -1;
        }

        int count=0;
        for(auto it:st){
            if(it>k){
                count++;
            }
        }

        return count;
    }
};