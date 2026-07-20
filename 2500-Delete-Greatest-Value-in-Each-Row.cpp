class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& v) {
        int n=v.size();
        int m=v[0].size();

        for(int i=0;i<v.size();i++){
            sort(v[i].begin(),v[i].end());
        }

        int total=0;
        
        for(int j=0;j<m;j++){
            int maxi=INT_MIN;
            for(int i=0;i<n;i++){
                maxi=max(v[i][j],maxi);
            }
            total+=maxi;
        }
        return total;
    }
};