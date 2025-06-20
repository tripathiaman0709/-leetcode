class Solution {
public:
    int maxDistance(string s, int k) {
        int n=s.size();
        int north=0;
        int south=0;
        int east=0;
        int west=0;
        int maxi=0;
        for(int i=0;i<n;i++){

            if(s[i]=='N'){
                north++;
            }
            if(s[i]=='S'){
                south++;
            }
            if(s[i]=='E'){
                east++;
            }
            if(s[i]=='W'){
                west++;
            }

            int md=abs(north-south)+abs(east-west);
            int steps=i+1;
            int extra=steps-md;

            if(extra!=0){
                extra=min(2*k,steps-md);
            }

            maxi=max(maxi,md+extra);
        }
        return maxi;

    }
};