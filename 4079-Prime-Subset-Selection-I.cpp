class Solution {
public:
    vector<int> maxPrimes(int n, int s) {
        //prime mean seive of eratosthenes
        vector<int>isprime(n+2,1);
        isprime[0]=0;
        isprime[1]=0;

        for(int i=2;i*i<n+1;i++){
            if(isprime[i]){
                for(int j=i*i;j<n+1;j+=i){
                    isprime[j]=0;
                }
            }
        }

        //now we got primes till 1e6
        //now just need to start from starting and get the number of primes

        int sum=0;
        vector<int>ans;
        for(int i=2;i<n+1;i++){
            if(isprime[i]){
                if(sum+i>s){
                    break;
                }
                sum+=i;
                ans.push_back(i);
            }
        }

        return ans;
    }
};