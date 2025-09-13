class Solution {
public:
    int maxFreqSum(string s) {
        int n=s.size();
        vector<int>v(256,0);
        for(int i=0;i<n;i++){
            v[s[i]]++;
        }
        int vmax=0;
        int cmax=0;

        for(int i=0;i<256;i++){
            if(i==97 || i==101 || i==105 || i==111 || i==117){
                vmax=max(vmax,v[i]);
            }else{
                cmax=max(cmax,v[i]);
            }
        }

        int ans=vmax+cmax;

        return ans;
    }
};