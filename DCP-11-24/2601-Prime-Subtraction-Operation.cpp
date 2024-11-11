class Solution {
public:

    bool isprime[1001];
    int maxN=1000;
    void sieve(){
        for(int i=0;i<=maxN;i++){
            isprime[i]=true;
        }
        isprime[0]=false;
        isprime[1]=false;

        for(int i=2;i*i<=maxN;i++){
            if(isprime[i]){
                for(int j=i*i;j<=maxN;j+=i){
                    isprime[j]=false;
                }
            }
        }
    }

    bool primeSubOperation(vector<int>& v) {
        int n=v.size();
        //going from right to left
        sieve();
        for(int i=n-2;i>=0;i--){
            if(v[i]<v[i+1]){
                continue;
            }
            //v[i]>=v[i+1]
            for(int j=2;j<v[i];j++){
                if(!isprime[j]){
                    continue;
                }
                if(v[i]-j<v[i+1]){
                    v[i]-=j;
                    break;
                }
            }
            if(v[i]>=v[i+1]){
                return false;
            }
        }
        return true;
    }
};