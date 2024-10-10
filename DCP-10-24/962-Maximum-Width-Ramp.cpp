class Solution {
public:
    int maxWidthRamp(vector<int>& a) {
        int n=a.size();
        int maxi=0;
        //sliding window optimization
        vector<int>v(n,a[n-1]);
        for(int i=n-2;i>=0;i--){
            v[i]=max(a[i],v[i+1]);
        }
        //this vector contains the biggest value present to the right of a particular number

        int l=0;
        int r=1;
        while(r<n){
            if(a[l]<=v[r]){
                maxi=max(maxi,r-l);
            }else{
                l++;
            }
            r++;
        }
        return maxi;
    }
};