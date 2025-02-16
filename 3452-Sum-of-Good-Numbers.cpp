class Solution {
public:
    int sumOfGoodNumbers(vector<int>& v, int k) {
        int n=v.size();
        int sum=0;
        for(int i=0;i<n;i++){
            int l=i-k;
            int r=i+k;
            int num=v[i];
            if(l<0 && r>n-1){
                sum+=num;
                continue;
            }

            if(l>=0 && num<=v[l]){
                continue;
            }
            if(r<=n-1 && num<=v[r]){
                continue;
            }

            sum+=num;                        
        }
        return sum;
    }
};