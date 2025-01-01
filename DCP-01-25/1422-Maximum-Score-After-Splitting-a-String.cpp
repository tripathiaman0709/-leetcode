class Solution {
public:
    int maxScore(string s) {
        int n=s.size();
        int zero=0;
        int one=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                one++;
            }
        }
        if(one==0 || one==n){
            return n-1;
        }
        int maxi=0;
        int sum=0;
        for(int i=0;i<n-1;i++){
            if(s[i]=='1'){
                one--;
            }else{
                zero++;
            }   
            sum=one+zero;
            maxi=max(maxi,sum);        
        }
        return maxi;
    }
};