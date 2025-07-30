class Solution {
public:
    int longestSubarray(vector<int>& v) {
        int n=v.size();
        int maxi=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,v[i]);
        }
        int maxlen=1;
        int len=0;
        for(int i=0;i<n;i++){
            if(v[i]==maxi){
                len++;
                maxlen=max(maxlen,len);
            }else{
                len=0;
            }
        }

        return maxlen;
    }
};