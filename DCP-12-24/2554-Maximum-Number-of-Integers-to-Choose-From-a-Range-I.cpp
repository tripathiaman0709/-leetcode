class Solution {
public:
    int maxCount(vector<int>& v, int x, int mxsum) {
        int n=v.size();
        unordered_set<int>st;
        for(int i=0;i<n;i++){
            st.insert(v[i]);
        }
        int sum=0;
        int count=0;
        for(int i=1;i<=x;i++){
            if(st.find(i)==st.end() && sum+i<=mxsum){
                count++;
                sum+=i;
            }
        }
        return count;
    }
};