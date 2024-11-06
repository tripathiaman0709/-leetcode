class Solution {
public:
    bool canSortArray(vector<int>& v) {
        int n=v.size();
        int count;
        for(int i=0;i<n;i++){
            count=0;
            for(int j=0;j<n-i-1;j++){
                if(v[j]<=v[j+1]){
                    continue;
                }else{
                    if(__builtin_popcount(v[j])!=__builtin_popcount(v[j+1])){
                        return false;
                    }else{
                        swap(v[j],v[j+1]);
                        count++;
                    }
                }
            }
            if(count==0){
                return true;//already sorted
            }
        }
        
        return true;
    }
};