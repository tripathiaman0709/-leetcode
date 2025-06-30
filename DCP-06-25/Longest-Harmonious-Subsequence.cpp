class Solution {
public:
    int findLHS(vector<int>& v) {
        int n=v.size();

        sort(v.begin(),v.end());
        // int maxi=0;
        // for(int i=0;i<n-1;i++){
        //     for(int j=i+1;j<n;j++){
        //         if(v[j]-v[i]==1){
        //             maxi=max(maxi,j-i+1);
        //         }
        //     }
        // }
        // return maxi;
        if(n==1){
            return 0;
        }
        int l=0;
        int r=0;
        int maxi=0;
        while(r<n){
            if(v[r]-v[l]==1){
                maxi=max(maxi,r-l+1);
                r++;
            }else if(v[r]-v[l]<1){
                r++;
            }else if(v[r]-v[l]>1){
                l++;
            }
        }

        return maxi;

    }
};