class Solution {
public:
    long long maxAlternatingSum(vector<int>& v) {
        //as we are squaring so no point of negative numbers
        int n=v.size();
        for(int i=0;i<n;i++){
            v[i]=abs(v[i]);
        }

        sort(v.rbegin(),v.rend());

        long long ans=0;
        int half=0;
        if(n%2){
            //odd number of values
            half=(n+1)/2;
        }else{
            half=n/2;
        }
        for(int i=0;i<half;i++){
            ans+=(v[i]*v[i]);
        }

        for(int i=n-1;i>=half;i--){
            ans-=(v[i]*v[i]);
        }

        return ans;
    }
};