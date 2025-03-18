class Solution {
public:
    int longestNiceSubarray(vector<int>& v) {
        int n=v.size();
        int i=0;
        int j=0;
        int ans=1;
        int x=0;
        while(j<n){
            while((v[j] & x)!=0){
                x=(x^v[i]);
                i++;
            }
            ans=max(ans,j-i+1);
            x=(x|v[j]);
            j++;
        }
        return ans;
    }
};