class Solution {
public:
    long long minSum(vector<int>& v1, vector<int>& v2) {
        int n=v1.size();
        int m=v2.size();
        long long v1zero=0;
        long long v2zero=0;
        long long v1sum=0;
        long long v2sum=0;
        for(int i=0;i<n;i++){
            if(v1[i]==0){
                v1zero++;
            }
            v1sum+=v1[i];
        }
        for(int i=0;i<m;i++){
            if(v2[i]==0){
                v2zero++;
            }
            v2sum+=v2[i];
        }

        long long mini=max(v1sum+v1zero,v2sum+v2zero);
        if(v1zero==0 && (v2sum+v2zero>v1sum)){
            return -1;
        }
        if(v2zero==0 && (v1sum+v1zero>v2sum)){
            return -1;
        }
        return mini;
    }
};