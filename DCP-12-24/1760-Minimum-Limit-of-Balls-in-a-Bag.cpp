class Solution {
public:
//using binary search on answer like coco eating bananas
//maximum of minimum

    bool fun(int n,int k,vector<int>&v){
        int count=0;
        for(int i=0;i<v.size();i++){
            count+=(v[i]+n-1)/n - 1;            
        }
        if(count<=k){
            return true;
        }else{
            return false;
        }
    }

    int minimumSize(vector<int>& v, int k) {
        int n=v.size();
        sort(v.begin(),v.end());
        int high=v[n-1];
        int low=1;
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(fun(mid,k,v)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};