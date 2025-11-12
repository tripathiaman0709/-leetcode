class Solution {
public:
    int minOperations(vector<int>& v) {
        int n=v.size();
        stack<int>st;
        int count=0;
        for(int i=0;i<n;i++){
            while(!st.empty() && st.top()>v[i]){
                st.pop();
            }
            if(v[i]==0){
                continue;
            }else if(st.empty() || st.top()<v[i]){
                st.push(v[i]);
                count++;
            }
        }
        return count;
    }
};