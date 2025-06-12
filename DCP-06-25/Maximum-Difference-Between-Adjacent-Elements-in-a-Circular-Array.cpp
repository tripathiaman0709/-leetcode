class Solution {
public:
    int maxAdjacentDistance(vector<int>& a) {
        int n=a.size();
        int maxi=abs(a[0]-a[n-1]);

        for(int i=0;i<n-1;i++){
            maxi=max(maxi,abs(a[i]-a[i+1]));
        }
        return maxi;
    }
};