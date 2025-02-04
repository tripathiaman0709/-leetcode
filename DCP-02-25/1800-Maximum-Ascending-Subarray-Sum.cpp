class Solution {
public:
    int maxAscendingSum(vector<int>& v) {
        //as all are positive numbers so no tomfoolery
        //easy peasy

        int n=v.size();
        int maxi=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,v[i]);
        }
        int sum=v[0];
        for(int i=1;i<n;i++){
            if(v[i]<=v[i-1]){
                sum=v[i];
            }else{
                sum+=v[i];
                maxi=max(maxi,sum);
            }
        }
        return maxi;
    }
};