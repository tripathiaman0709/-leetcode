class Solution {
public:
    int longestPalindrome(vector<string>& v) {
        int n=v.size();

        //using mapping

        unordered_map<string,int>mpp;
        int len=0;
        for(int i=0;i<n;i++){
            string s=v[i];
            char ch1=s[0];
            char ch2=s[1];
            string ulta="";
            ulta+=ch2;
            ulta+=ch1;
            if(mpp[ulta]>0){
                len+=4;
                mpp[ulta]--;
            }else{
                mpp[s]++;
            }
        }
        for(int i=0;i<n;i++){
            string s=v[i];
            char ch1=s[0];
            char ch2=s[1];
            string ulta="";
            ulta+=ch2;
            ulta+=ch1;
            if(s==ulta && mpp[s]>0){
                len+=2;
                return len;
            }
        }
        return len;
    }
};