class Solution {
public:
    bool check(vector<int>& v) {
        int n=v.size();
        vector<int>sorted=v;
        sort(sorted.begin(),sorted.end());
        //just one simple way 
        //ima just brute forcing

        for(int i=0;i<n;i++){
            vector<int>ans;
            for(int j=i;j<n;j++){
                ans.push_back(v[j]);
            }
            for(int j=0;j<i;j++){
                ans.push_back(v[j]);
            }

            if(ans==sorted){
                return true;
            }
        }
        return false;
    }
};