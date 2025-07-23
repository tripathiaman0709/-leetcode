class Solution {
public:
    vector<string> partitionString(string s) {
        int n=s.size();
        //simply brute forcing it
        unordered_set<string>st;
        string ss="";
        vector<string>ans;
        for(int i=0;i<n;i++){
            ss+=s[i];
            if(st.find(ss)==st.end()){
                st.insert(ss);
                ans.push_back(ss);
                ss="";
            }
        }
        return ans;
    }
};