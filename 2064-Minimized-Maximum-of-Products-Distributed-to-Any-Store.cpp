class Solution {
public:

    bool fun(int x,vector<int>&v,int n){
        int k=n;
        for(int i=0;i<v.size();i++){
            k-=((v[i]+x-1)/x);
            if(k<0){
                return false;
            }
        }
        return true;
    }

    int minimizedMaximum(int n, vector<int>& v) {

        int low=1;
        int high=*max_element(begin(v),end(v));
        int ans=0;

        while(low<=high){
            int mid=low+(high-low)/2;

            if(fun(mid,v,n)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};