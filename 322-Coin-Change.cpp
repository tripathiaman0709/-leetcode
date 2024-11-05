class Solution {
public:
    int coinChange(vector<int>& c, int t) {
        //making a vector of size amount
        vector<int>v(t+1,t+1);
        v[0]=0;
        //coins required to reach to 0 is 0
        for(int i=1;i<=t;i++){
            for(auto it:c){
                if(it<=i && v[i-it]!=t+1){    
                    v[i]=min(v[i-it]+1,v[i]);
                }
            }
        }
        if(v[t]==t+1){
            return -1;
        }else{
            return v[t];
        }
    }
};