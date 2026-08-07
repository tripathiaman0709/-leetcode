class Solution {
public:
    long long maxPairStrength(vector<int>& v) {
        long long n=v.size();
        long long maxi=0;
        for(long long i=0;i<n;i++){
            long long x=v[i];
            for(long long j=i+1;j<n;j++){
                long long y=v[j];
                long long hcf=gcd(x,y);
                hcf*=hcf;
                long long pro=x*y;

                long long cal=pro/hcf;
                maxi=max(maxi,cal);
            }
        }

        return maxi;
    }
};