class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& v, vector<vector<int>>& q) {
        int n=v.size();
        vector<int>cum(n,0);
        for(int i=1;i<n;i++){
            if(v[i]%2 == v[i-1]%2){
                cum[i]=cum[i-1]+1;
            }else{
                cum[i]=cum[i-1];
            }
        }
        vector<bool>ans;
        for(auto it:q){
            int x=it[0];
            int y=it[1];

            if(cum[y]==cum[x]){
                ans.push_back(true);
            }else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};