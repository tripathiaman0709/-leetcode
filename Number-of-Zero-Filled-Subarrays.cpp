class Solution {
public:

    long long fact(long long n){
        return ((n)*(n+1)) >> 1;
    }

    long long zeroFilledSubarray(vector<int>& v) {
        long long count=0;
        int n=v.size();
        // for(int i=0;i<n;i++){
        //     if(v[i]==0){
        //         count++;
        //     }
        // }
        long long adder=0;
        for(int i=0;i<n;i++){
            if(v[i]==0){
                adder++;
            }else{
                if(adder){
                    count+=fact(adder);
                }
                adder=0;
            }
        }
        count+=fact(adder);
        return count;
    }
};