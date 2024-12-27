class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& v) {
        int n=v.size();
        //firstly using the brute force approach
        //TC -> O(N^2)
        int maxi=0;
        // for(int i=0;i<n-1;i++){
        //     for(int j=i+1;j<n;j++){
        //         int x=v[i]+v[j]+i-j;
        //         maxi=max(maxi,x);
        //     }
        // }
        // return maxi;
        
        vector<int>a(n,0);
        a[0]=0;
        for(int i=1;i<n;i++){
            a[i]=max(v[i-1]+(i-1),a[i-1]);
        }
        for(int i=1;i<n;i++){
            int x=v[i]-i + a[i];
            maxi=max(maxi,x);
        }

        return maxi;
    }
};