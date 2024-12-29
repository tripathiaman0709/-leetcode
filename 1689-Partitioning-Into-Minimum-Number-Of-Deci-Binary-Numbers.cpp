class Solution {
public:
    int minPartitions(string s) {
        int n=s.size();
        int maxi=0;
        for(int i=0;i<n;i++){
            int x=s[i]-48;
            maxi=max(maxi,x);
        }
        return maxi;
    }
};