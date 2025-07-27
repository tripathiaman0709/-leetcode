class Solution {
public:
    int countHillValley(vector<int>& v) {
        int n=v.size();

        int hill=1;
        int valley=1;

        int counthill=0;
        int countvalley=0;

        for(int i=1;i<n-1;i++){
            int num=v[i];
            int rightnum=-1;
            int leftnum=-1;

            for(int l=i-1;l>=0;l--){
                
                if(v[l]!=v[i]){
                    leftnum=v[l];
                    break;
                }
            }
            for(int r=i+1;r<n;r++){
                
                if(v[r]!=v[i]){
                    rightnum=v[r];
                    break;
                }
            }

            if(hill==1 && leftnum<num && rightnum<num && leftnum!=-1 && rightnum!=-1){
                counthill++;
                hill=0;
                valley=1;
            }
            if(valley==1 && leftnum>num && rightnum>num && leftnum!=-1 && rightnum!=-1){
                countvalley++;
                valley=0;
                hill=1;
            }

        }
        int ans=counthill+countvalley;
        return ans;
    }
};