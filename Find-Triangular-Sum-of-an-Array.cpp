class Solution {
public:
    int triangularSum(vector<int>& v) {
        int n=v.size();
        if(n==1){
            return v[0];
        }
        vector<int>prev;
        prev=v;
        while(n>1){
            vector<int>vec(n-1);
            for(int i=0;i<n-1;i++){
                vec[i]=(prev[i]+prev[i+1])%10;
            }
            prev=vec;
            n--;
            if(n==1){
                return vec[0];
            }
        }
        return 0;
    }
};