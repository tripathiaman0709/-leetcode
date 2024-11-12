class Solution {
public:

    int fun(vector<vector<int>>& v,int x){
        int low=0;
        int high=v.size()-1;

        int mid;
        int maxbeauty=0;
        while(low<=high){
            mid=low+(high-low)/2;

            if(v[mid][0]>x){
                high=mid-1;
            }else{
                maxbeauty=max(maxbeauty,v[mid][1]);
                low=mid+1;
            }
        }
        return maxbeauty;
    }

    vector<int> maximumBeauty(vector<vector<int>>& v, vector<int>& q) {
        int n=v.size();
        int m=q.size();
        vector<int>ans(m,0);
        sort(v.begin(),v.end());
        int maxbeauty=v[0][1];
        for(int i=1;i<n;i++){
            maxbeauty=max(v[i][1],maxbeauty);
            v[i][1]=maxbeauty;
        }

        for(int i=0;i<m;i++){
            ans[i]=fun(v,q[i]);
        }
        return ans;
    }
};