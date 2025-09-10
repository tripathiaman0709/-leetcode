class Solution {
public:
    int minimumTeachings(int total, vector<vector<int>>& l, vector<vector<int>>& f) {
        int n=f.size();
        unordered_set<int>s;
        //to store sad friend

        for(int i=0;i<n;i++){
            int u=f[i][0];
            int v=f[i][1];

            unordered_set<int>st;
            
            for(int i=0;i<l[u-1].size();i++){
                st.insert(l[u-1][i]);
            }
            for(int i=0;i<l[v-1].size();i++){
                st.insert(l[v-1][i]);
            }

            int sz1=l[u-1].size();
            int sz2=l[v-1].size();

            if(sz1+sz2 == st.size()){
                //no common elements
                s.insert(u-1);
                s.insert(v-1);
            }
            st.clear();
        }
        vector<int>mpp(total+1,0);
        for(auto it:s){
            for(auto x:l[it]){
                mpp[x]++;
            }
        }

        //now stored the most repeating language

        int maxi=0;
        for(auto it:mpp){
            if(it>0){
                maxi=max(maxi,it);
            }
        }
        int ans=s.size()-maxi;
        return ans;
    }
};