class Solution {
public:
    int maximumDifference(vector<int>& v) {
        int n=v.size();

        int ans=-1;

        // for(int i=0;i<n-1;i++){
        //     for(int j=i+1;j<n;j++){
        //         if(v[j]>v[i]){
        //             ans=max(ans,v[j]-v[i]);
        //         }
        //     }
        // }

        //trying to minimize the time complexity
        //thinking of the greatest/largest element to the right of each element

        vector<int>maxright(n,v[n-1]);

        for(int i=n-2;i>=0;i--){
            maxright[i]=max(maxright[i+1],v[i]);
        }

        for(int i=0;i<n-1;i++){
            if(maxright[i]>v[i]){
                ans=max(maxright[i]-v[i],ans);
            }
        }
        
        return ans;
    }
};