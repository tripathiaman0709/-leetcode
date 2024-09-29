class Solution {

public:
    int findLongestChain(vector<vector<int>>& a) {
        int n=a.size();
        sort(a.begin(),a.end());
        //tabulation
        vector<int>v(n,1);
        int maxi=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(a[i][0]>a[j][1]){
                    v[i]=max(v[i],v[j]+1);
                    maxi=max(maxi,v[i]);
                }
            }
        }
        return maxi;
    }
};