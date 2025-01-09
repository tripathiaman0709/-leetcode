class Solution {
public:

    int hcf(int x,int y){
        if(y==0){
            return x;
        }
        return hcf(y,x%y);
    }
    int lcm(int x,int y){
        int ans=(x*y)/hcf(x,y);
        return ans;
    }

    int maxLength(vector<int>& v) {
        int n=v.size();
        int maxi=1;
        for(int i=0;i<n;i++){
            int pro=v[i];
            int lc=v[i];
            int hc=v[i];
            int count=1;
            for(int j=i+1;j<n;j++){
                pro*=v[j];
                lc=lcm(lc,v[j]);
                hc=hcf(hc,v[j]);

                if(pro==lc*hc){
                    count++;
                    maxi=max(count,maxi);
                }else{
                    break;
                }
            }
        }
        return maxi;

    }
};