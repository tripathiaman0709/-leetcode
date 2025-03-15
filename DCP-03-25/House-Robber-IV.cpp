class Solution {
public:
    // int fun(vector<int>&v,int i,int k,vector<vector<int>>&vec){
    //     if(k==0){
    //         return 0;
    //     }
    //     if(i>=v.size()){
    //         return INT_MAX;
    //     }
    //     if(vec[i][k]!=-1){
    //         return vec[i][k];
    //     }
    //     int result=0;
    //     int take=max(v[i],fun(v,i+2,k-1,vec));
    //     int nottake=fun(v,i+1,k,vec);

    //     return vec[i][k]=min(take,nottake);
    // }

    bool ispossible(vector<int>&v,int mid,int k){
        int n=v.size();
        int count=0;
        for(int i=0;i<n;i++){
            if(v[i]<=mid){
                count++;
                i++;//for adjacency
            }
        }
        return (count>=k);
    }
    int minCapability(vector<int>& v, int k) {
        // //basic dp problem
        // //take or skip way

        // int n=v.size();
        // //vector,index,k

        // //now memoizing
        // vector<vector<int>>vec(n+1,vector<int>(k+1,-1));
        // return fun(v,0,k,vec);        

        //as giving TLE 
        //so using binary search as minimum of maximum type problem

        int n=v.size();
        int l=*min_element(v.begin(),v.end());
        int r=*max_element(v.begin(),v.end());
        int ans=r;
        while(l<=r){
            int mid=l+(r-l)/2;

            if(ispossible(v,mid,k)){
                ans=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
};