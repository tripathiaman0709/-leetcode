class Solution {
public:

    int isprime[100001];

    void prime(){
        for(int i=0;i<=100000;i++){
            isprime[i]=1;
        }
        isprime[0]=0;
        isprime[1]=0;

        for(int i=2;i*i<=1e5;i++){
            if(isprime[i]==1){
                for(int j=i*2;j<=1e5;j+=i){
                    isprime[j]=0;
                }
            }
        }
    }

    long long splitArray(vector<int>& v) {
        //0 and 1 are not primes
        prime();
        long long n=v.size();
        long long sum1=0;
        long long sum2=0;
        for(long long i=0;i<n;i++){
            if(isprime[i]){
                sum1+=v[i];
            }else{
                sum2+=v[i];
            }
        }
        long long ans=abs(sum1-sum2);
        return ans;
    }
};