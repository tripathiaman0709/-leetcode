class Solution {
public:
    bool canSortArray(vector<int>& v) {
        int n=v.size();
        int cmin=v[0];
        int cmax=v[0];
        int pmax=-1;

        for(int i=0;i<n;i++){
            if(__builtin_popcount(cmax)==__builtin_popcount(v[i])){
                cmin=min(cmin,v[i]);
                cmax=max(cmax,v[i]);
            }else{
                if(pmax>cmin){
                    return false;
                }else{
                    pmax=cmax;
                    cmin=v[i];
                    cmax=v[i];
                }
            }
        }
        //checking for last
        if(pmax>cmin){
            return false;
        }
        return true;
    }
};