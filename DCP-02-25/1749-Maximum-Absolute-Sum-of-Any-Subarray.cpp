class Solution {
public:
    int maxAbsoluteSum(vector<int>& v) {
        int n=v.size();
        int maxi=INT_MIN;
        int sum=0;
        //trying out kadane's algorithm
        for(int i=0;i<n;i++){
            sum+=v[i];
            if(sum<0){
                sum=0;
            }
            maxi=max(maxi,sum);
        }
        vector<int>a(n);
        for(int i=0;i<n;i++){
            a[i]=-v[i];
        }
        int maxi1=INT_MIN;
        int sum1=0;
        //trying out kadane's algorithm
        for(int i=0;i<n;i++){
            sum1+=a[i];
            if(sum1<0){
                sum1=0;
            }
            maxi1=max(maxi1,sum1);
        }
        int ans=max(maxi,maxi1);
        return ans;
    }
};