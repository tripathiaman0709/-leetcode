class Solution {
public:

    long long hcf(long long a, long long b) {
        if (b == 0) return a;
        return hcf(b, a % b);
    }

    long long gcdSum(vector<int>& v) {
        long long n=v.size();
        long long maxi=0;
        vector<long long>maxv(n,0);

        for(long long i=0;i<n;i++){
            if(maxi<v[i]){
                maxi=v[i];
            }
            maxv[i]=maxi;
        }
        vector<long long>pre;
        for(long long i=0;i<n;i++){
            long long x=hcf(v[i],maxv[i]);
            pre.push_back(x);
        }

        sort(pre.begin(),pre.end());
        long long sum=0;
        for(long long i=0;i<pre.size()/2;i++){
            long long val=gcd(pre[i],pre[pre.size()-i-1]);

            sum+=val;
        }
        return sum;
    }
};