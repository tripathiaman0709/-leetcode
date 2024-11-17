class Solution {
public:
    int countValidSelections(vector<int>& v) {
        int n=v.size();
        if(n==1){
            if(v[0]==0){
                return 2;
            }else{
                return 0;
            }
        }
        vector<int>pre(n,0);
        vector<int>suff(n,0);
        
        pre[0]=v[0];
        suff[n-1]=v[n-1];

        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+v[i];
        }
        for(int i=n-2;i>=0;i--){
            suff[i]=suff[i+1]+v[i];
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(v[i]==0 && (abs(pre[i]-suff[i])==0)){
                count+=2;
            }
            if(v[i]==0 && (abs(pre[i]-suff[i])==1)){
                count++;
            }
        }
        return count;
    }
};