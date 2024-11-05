class Solution {
public:
    int minOperations(vector<int>&v, int k) {
        int n=v.size();
        int x=0;
        for(int i=0;i<n;i++){
            x^=v[i];
        }
        x^=k;
        int count=0;
        while(x){
            if(x%2){
                count++;
            }
            x/=2;
        }
        return count;
    }
};