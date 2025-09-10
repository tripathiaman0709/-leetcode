class Solution {
public:
    int minOperations(string s) {
        int n=s.size();
        //need to make each characters equal to a
        int maxi=0;
        for(int i=0;i<n;i++){
            if(s[i]=='a'){
                continue;
            }
            maxi=max(maxi,'z'-s[i]+1);
        }
        return maxi;
    }
};