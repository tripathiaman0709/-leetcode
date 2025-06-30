class Solution {
public:
    int findLHS(vector<int>& v) {
        int n=v.size();

        sort(v.begin(),v.end());
        int maxi=0;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(v[j]-v[i]==1){
                    maxi=max(maxi,j-i+1);
                }
            }
        }
        return maxi;
    }
};