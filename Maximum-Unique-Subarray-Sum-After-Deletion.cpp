class Solution {
public:
    int maxSum(vector<int>& v) {
        int n=v.size();
        //isn't this sum of all unique positive numbers
        unordered_set<int>st;
        for(int i=0;i<n;i++){
            if(v[i]>0){
                st.insert(v[i]);
            }
        }
        if(st.size()==0){
            int maxi=INT_MIN;
            for(int i=0;i<n;i++){
                maxi=max(maxi,v[i]);
            }
            return maxi;
        }
        int sum=0;
        for(auto it:st){
            sum+=it;
        }
        return sum;
    }
};