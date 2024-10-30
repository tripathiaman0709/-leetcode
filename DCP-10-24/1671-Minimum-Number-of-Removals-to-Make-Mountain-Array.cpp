class Solution {
public:
    int minimumMountainRemovals(vector<int>& a) {
        int n=a.size();
        vector<int>lis(n,1);
        vector<int>lds(n,1);
        //initialising lis and lds with 1 

        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(a[j]<a[i]){
                    lis[i]=max(lis[i],lis[j]+1);
                }
            }
        }

        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(a[i]>a[j]){
                    lds[i]=max(lds[i],lds[j]+1);
                }
            }
        }

        int mini=n;
        for(int i=0;i<n;i++){
            if(lis[i]>1 && lds[i]>1){
                int x=n-lis[i]-lds[i]+1;
                mini=min(mini,x);
            }
        }
        return mini;
    }
};