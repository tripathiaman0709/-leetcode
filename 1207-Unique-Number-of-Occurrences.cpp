class Solution {
public:
    bool uniqueOccurrences(vector<int>& v) {
        int n=v.size();
        unordered_map<int,int>mpp;
        unordered_set<int>st;
        for(int i=0;i<n;i++){
            mpp[v[i]]++;
        }
        for(auto it:mpp){
            st.insert(it.second);
        }
        if(mpp.size()==st.size()){
            return true;
        }else{
            return false;
        }
        

        
    }
};