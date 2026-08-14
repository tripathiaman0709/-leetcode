class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n=s.size();
        unordered_map<char,int>mpp;
        int i=0;
        int j=0;
        int maxi=2;
        
        while(i<n){
            mpp[s[i]]++;
            while(mpp[s[i]]>2 && j<n){
                mpp[s[j]]--;
                j++;
            }
            maxi=max(maxi,i-j+1);
            i++;
        }
        return maxi;
    }
};