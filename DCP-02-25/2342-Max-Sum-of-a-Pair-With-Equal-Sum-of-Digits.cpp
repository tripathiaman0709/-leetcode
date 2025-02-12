class Solution {
public:

    int fun(int n){
        int sum=0;
        while(n){
            sum+=(n%10);
            n/=10;
        }
        return sum;
    }

    int maximumSum(vector<int>& v) {
        int n=v.size();
        int ans=-1;
        // unordered_map<int,int>mpp;
        //using vector of size 82 instead
        vector<int>mpp(82);
        for(int i=0;i<n;i++){
            int digitsum=fun(v[i]);

            if(mpp[digitsum]>0){
                ans=max(ans,v[i]+mpp[digitsum]);
                //updating the maximum
                mpp[digitsum]=max(v[i],mpp[digitsum]);
            }else{
                mpp[digitsum]=v[i];
            }            
        }
        return ans;
    }
};