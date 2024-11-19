class Solution {

bool fun(vector<int>& v, vector<vector<int>>& q,int k){
    int n=v.size();
    vector<int>ls(n+1,0);
    for(int i=0;i<k;i++){
        int s=q[i][0];
        int e=q[i][1];
        int val=q[i][2];

        ls[s]+=val;
        ls[e+1]-=val;
    }
    vector<int>pre(n,0);
    pre[0]=ls[0];
    for(int i=1;i<n;i++){
        pre[i]=pre[i-1]+ls[i];
    }
    for(int i=0;i<n;i++){
        if(v[i]>pre[i]){
            return false;
        }
    }
    return true;
}

public:
    int minZeroArray(vector<int>& v, vector<vector<int>>& q) {
        //using binary search on answer of line sweep algorthm

        int low=0;
        int high=q.size();
        int ans=-1;

        while(low<=high){
            int mid=low+(high-low)/2;
            if(fun(v,q,mid)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};