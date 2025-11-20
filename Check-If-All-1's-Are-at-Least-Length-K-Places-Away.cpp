class Solution {
public:
    bool kLengthApart(vector<int>& v, int k) {
        int n=v.size();
        int dis=1000001;
        for(int i=0;i<n;i++){
            if(v[i]==1){
                if(dis<k){
                    return false;
                }
                dis=0;
            }else{
                dis++;
            }
        }
        return true;
    }
};