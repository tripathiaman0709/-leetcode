class Solution {
public:
    int firstMissingPositive(vector<int>& v) {
        int n=v.size();
        unordered_set<int>st;
        for(auto it:v){
            st.insert(it);
        }
        for(int i=1;i<=100001;i++){
            if(st.find(i)==st.end()){
                return i;
            }
        }
        return -1;
    }
};