class Solution {
public:

    long long hcf(long long x,long long y){
        if(y==0){
            return x;
        }
        return hcf(y,x%y);
    }
    long long lcm(long long x,long long y){
        return x*y/hcf(x,y);
    }


    long long maxScore(vector<int>& a) {
        int n=a.size();
        if(n==1){
            return a[0]*a[0];
        }else{
            long long lcmfull=a[0];
            long long gcdfull=a[0];
            for(int i=0;i<n;i++){
                gcdfull=hcf(gcdfull,a[i]);
                lcmfull=lcm(lcmfull,a[i]);
            }
            long long full=lcmfull*gcdfull;

            long long gcdless=a[1];
            long long lcmless=a[1];
            for(int i=1;i<n;i++){
                gcdless=hcf(gcdless,a[i]);
                lcmless=lcm(lcmless,a[i]);
            }
            long long less=lcmless*gcdless;

            long long maxi=max(less,full);

            long long x=0;
            while(x<n){
            long long past=a[x];
            a[x]=a[0];    
            long long lcmfull=a[0];
            long long gcdfull=a[0];
            for(int i=1;i<n;i++){
                gcdfull=hcf(gcdfull,a[i]);
                lcmfull=lcm(lcmfull,a[i]);
            }
            long long full=lcmfull*gcdfull;
            maxi=max(full,maxi);
            a[x]=past;
            x++;
            }
            
            return maxi;

        }
    }
};