class Solution {
public:
    int sumOfGoodSubsequences(vector<int>& v) {
        int n=v.size();
        map<int,int>count,sum;

        int mod=1e9+7;
        for(auto i:v){
            count[i]+=(1+count[i+1]+count[i-1])%mod;
            count[i] %= mod;
            sum[i] += (sum[i - 1] + sum[i + 1]) % mod;
            sum[i] %= mod;

            sum[i] += (long long)(count[i - 1] + count[i + 1] + 1) % mod * i % mod;
            sum[i] %= mod;
        }
        int ans=0;
        for(auto it:sum){
            ans+=it.second;
            ans%=mod;
        }

        return ans;
    }
};