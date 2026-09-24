class Solution {
public:

    int fun(int n){
        int sum=0;
        while(n){
            sum+=n%10;
            n/=10;
        }

        return sum;
    }
    
    int smallestIndex(vector<int>& v) {
        int n=v.size();

        for(int i=0;i<n;i++){
            int x=v[i];
            int sum=fun(x);
            if(sum==i){
                return i;
            }
        }
        return -1;
    }
};