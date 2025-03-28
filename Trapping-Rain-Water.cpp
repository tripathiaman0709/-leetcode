class Solution {
public:
    int trap(vector<int>& v) {
        int n=v.size();
        //brute forcing it first
        //simply finding next greater to left and next greater to right
        // int ans=0;
        // for(int i=0;i<n;i++){
        //     int building=v[i];
        //     int nextlbig=v[i];
        //     for(int j=i;j>=0;j--){
        //         if(v[j]>building){
        //             nextlbig=v[j];
        //             break;
        //         }
        //     }
        //     int nextrbig=v[i];
        //     for(int j=i;j<n;j++){
        //         if(v[j]>building){
        //             nextrbig=v[j];
        //             break;
        //         }
        //     }
        //     if(min(nextlbig,nextrbig)-building>0){
        //         ans+=min(nextlbig,nextrbig)-building;
        //     }
        // }
        // return ans;

        //making two arrays to store lmax and right max upto a cerain index
        if(n==1){
            return 0;
        }
        vector<int>lmax(n);
        vector<int>rmax(n);
        lmax[0]=v[0];
        for(int i=1;i<n;i++){
            lmax[i]=max(lmax[i-1],v[i]);
        }

        rmax[n-1]=v[n-1];
        for(int i=n-2;i>=0;i--){
            rmax[i]=max(rmax[i+1],v[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(min(lmax[i],rmax[i])-v[i] >0){
                ans+=min(lmax[i],rmax[i])-v[i];
            }
        }
        return ans;
    }
};