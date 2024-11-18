class Solution {
public:
    vector<int> decrypt(vector<int>& v, int k) {
        int n=v.size();
        int sz=n+n;

        vector<int>ans(sz);
        for(int i=0;i<n;i++){
            ans[i]=v[i];
        }
        for(int i=n;i<sz;i++){
            ans[i]=v[i-n];
        }

        vector<int>sol(n);
        if(k==0){
            return sol;
        }else if(k>0){
            for(int i=0;i<n;i++){
                int sum=0;
                for(int j=i+1;j<=i+k;j++){
                    sum+=ans[j];
                }
                sol[i]=sum;
            }
            return sol;
        }else{
            for(int i=sz-1;i>=n;i--){
                int sum=0;
                for(int j=i-1;j>=i+k;j--){
                    sum+=ans[j];
                }
                sol[i-n]=sum;
            }
            return sol;
        }
    }
};