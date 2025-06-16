class Solution {
public:
    int maximumDifference(vector<int>& v) {        
        // for(int i=0;i<n-1;i++){
        //     for(int j=i+1;j<n;j++){
        //         if(v[j]>v[i]){
        //             ans=max(ans,v[j]-v[i]);
        //         }
        //     }
        // }

        //trying to minimize the time complexity
        //thinking of the greatest/largest element to the right of each element

        // vector<int>maxright(n,v[n-1]);

        // for(int i=n-2;i>=0;i--){
        //     maxright[i]=max(maxright[i+1],v[i]);
        // }

        // for(int i=0;i<n-1;i++){
        //     if(maxright[i]>v[i]){
        //         ans=max(maxright[i]-v[i],ans);
        //     }
        // }

        //now thinking of reducing the space complexity
        //as taking O(n) space

        //could we think of two pointer approach or something like that

        int xMin=v[0], n=v.size();
        int maxD=-1;
        for(int i=1; i<n; i++){
            int x=v[i];
            if (x<=xMin)
                xMin=x;
            else maxD=max(maxD, x-xMin); 
        }
        return maxD;
        
        // return ans;
    }
};