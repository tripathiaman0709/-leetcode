class Solution {
public:
    int longestSubarray(vector<int>& v) {
        int n=v.size();
        int count1=0;
        for(int i=0;i<n;i++){
            if(v[i]==1){
                count1++;
            }
        }

        if(count1==n){
            return n-1;
        }
        if(count1==0){
            return 0;
        }

        int maxlen=0;
        //i think sliding window is the approach that will work here
        int i=0;
        int j=0;
        int count0=0;
        while(j<n){
            if(v[j]==0 && count0<1){
                count0++;
                j++;
            }else if(v[j]==1 && count0<=1){
                j++;
            }else{
                while(v[i]!=0){
                    i++;
                }
                i++;
                count0=0;
            }
            maxlen=max(maxlen,j-i);
        }
        return maxlen-1;
    }
};