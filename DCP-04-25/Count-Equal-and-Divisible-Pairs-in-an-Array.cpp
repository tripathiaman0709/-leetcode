class Solution {
public:
    int countPairs(vector<int>& v, int k) {
        int n=v.size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(v[i]!=v[j]){
                    continue;
                }
                if(i*j % k==0){
                    count++;
                }
            }
        }
        return count;
    }
};