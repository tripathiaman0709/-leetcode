class Solution {
public:
    int numberOfSubstrings(string s) {
        //as string length is 1e4 so may be can try O(n^2)

        int n=s.size();
        //using sliding window approach again
        unordered_map<char,int>mpp;
        int j=0;
        int i=0;
        int count=0;
        while(j<n){
            mpp[s[j]]++;
            while(mpp['a']>0 && mpp['b']>0 && mpp['c']>0){
                count+=(n-j);
                mpp[s[i]]--;
                if(mpp[s[i]]==0){
                    mpp.erase(s[i]);
                }
                i++;
            }
            j++;            
        }
        return count;
    }
};