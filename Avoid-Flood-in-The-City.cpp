class Solution {
public:
    vector<int> avoidFlood(vector<int>& v) {
        int n=v.size();
        set<int>st;//storing the dry days where we can dry other lakes
        vector<int>ans(n,1);
        unordered_map<int,int>mpp;

        for(int i=0;i<n;i++){
            if(v[i]==0){
                st.insert(i);
            }else{
                ans[i]=-1;
                //checking if flood 
                if(mpp.count(v[i])){
                    auto it=st.lower_bound(mpp[v[i]]);
                    if(it==st.end()){
                        return {};
                    }
                    ans[*it]=v[i];
                    st.erase(it);
                }
            }
            mpp[v[i]]=i;
        }
        return ans;
    }
};