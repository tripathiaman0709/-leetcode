class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        int n=a.size();
        vector<int>v(n,1);
        int maxi=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(a[j]<a[i]){
                    v[i]=max(v[i],v[j]+1);
                    maxi=max(maxi,v[i]);
                }
            }
        }
        return maxi;
    }
};