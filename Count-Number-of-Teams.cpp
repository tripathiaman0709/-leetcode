class Solution {
public:
    int numTeams(vector<int>& a) {
        int n=a.size();
        int sum=0;

        for(int i=1;i<n-1;i++){
            int leftsmaller=0;
            int rightlarger=0;

            for(int j=0;j<i;j++){
                if(a[j]<a[i]){
                    leftsmaller++;
                }
            }
            for(int j=i+1;j<n;j++){
                if(a[j]>a[i]){
                    rightlarger++;
                }
            }

            sum+=leftsmaller*rightlarger;


            int leftlarger=i-leftsmaller;
            int rightsmaller=n-i-rightlarger-1;
            sum+=leftlarger*rightsmaller;
        }
        return sum;
        
    }
};