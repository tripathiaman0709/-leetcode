class Solution {
public:

    int fun(vector<int>&t,vector<int>&b,int v){
        int tmin=0;
        int bmin=0;
        for(int i=0;i<t.size();i++){    
            if(t[i]!=v && b[i]!=v){
                return -1;
            }else if(t[i]==v && b[i]!=v){
                bmin++;
            }else if(t[i]!=v && b[i]==v){
                tmin++;
            }else{
                continue;
            }
        }
        return min(tmin,bmin);
    }

    int minDominoRotations(vector<int>& t, vector<int>& b) {
        int n=t.size();
        //saari values ke liye brute force way me check krlo 
        //as only six possible values hi toh hai
        int ans=INT_MAX;
        for(int i=1;i<=6;i++){
            int val=fun(t,b,i);
            if(val!=-1){
                ans=min(ans,val);
            }
        }
        if(ans==INT_MAX){
            return -1;
        }
        return ans;
    }
};