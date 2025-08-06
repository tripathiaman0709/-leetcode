class Solution {
public:
    int minRemoval(vector<int>& v, int k) {
        int n=v.size();
        sort(v.begin(),v.end());


        int i=0;
        int j=1;
        if(n==1){
            j=i;
        }
        int mini=min(v[i],v[j]);
        int maxi=max(v[i],v[j]);

        int ans=INT_MAX;


        while(j<n){
            while((long long)k*mini<(long long)maxi){
                i++;
                mini=v[i];
            }
            ans=min(ans,n-(j-i+1));
            j++;
            if(i<n){
                mini=v[i];
            }
            if(j<n){
                maxi=v[j];
            }
        }
        return ans;
    }
};