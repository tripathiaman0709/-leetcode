class Solution {
public:

    bool check(int curr,vector<int>&v,int p){
        int count=0;
        int n=v.size();
        for(int i=1;i<n;i++){
            if(v[i]-v[i-1]<=curr){
                i++;
                count++;
            }
        }

        return count>=p;
    }

    int minimizeMax(vector<int>& v, int p) {
        //minimizing the maximum
        //suna suna lg rha hai
        //binary search on answer vala hai kya..
        int n=v.size();

        sort(v.begin(),v.end());

        int l=0;
        int r=v[n-1]-v[0];

        int ans=INT_MAX;

        while(l<=r){
            int mid=l+(r-l)/2;

            if(check(mid,v,p)){
                ans=mid;
                r=mid-1;
                //aur chota answer nikaalne ki koshish
            }else{
                l=mid+1;
            }
        }

        return ans;        
    }
};