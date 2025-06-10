class Solution {
public:
    int maxDifference(string s) {
        int oddmax=0;
        int evenmin=101;

        int n=s.size();

        vector<int>freq(26,0);

        for(int i=0;i<n;i++){
            freq[s[i]-'a']++;
        }

        for(int i=0;i<26;i++){
            if(freq[i]%2){
                oddmax=max(oddmax,freq[i]);
            }else{
                if(freq[i]!=0){
                    evenmin=min(evenmin,freq[i]);
                }
            }
        }
        int ans=oddmax-evenmin;

        return ans;
    }
};