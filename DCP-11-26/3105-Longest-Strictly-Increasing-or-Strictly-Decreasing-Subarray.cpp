class Solution {
public:
    int longestMonotonicSubarray(vector<int>& v) {
        int n=v.size();
        int inc=1;
        int dec=1;

        int minc=1;
        int mdec=1;

        for(int i=0;i<n-1;i++){
            if(v[i+1]>v[i]){
                inc++;
                minc=max(minc,inc);
            }else{
                inc=1;
            }
        }
        for(int i=0;i<n-1;i++){
            if(v[i+1]<v[i]){
                dec++;
                mdec=max(mdec,dec);
            }else{
                dec=1;
            }
        }

        int ans=max(minc,mdec);

        return ans;
    }
};