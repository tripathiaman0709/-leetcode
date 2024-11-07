class Solution {
public:
    bool canPlaceFlowers(vector<int>& v, int k) {
        int n=v.size();
        int count=0;
        for(int i=0;i<n;i++){
            if(v[i]==0){
                bool a=(i==0   || v[i-1]==0);
                bool b=(i==n-1 || v[i+1]==0);

                if(a && b){
                    v[i]=1;
                    count++;
                }                
            }
        }
        if(count>=k){
            return true;
        }else{
            return false;
        }
    }
};