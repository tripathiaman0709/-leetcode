class Solution {
public:
    string longestPalindrome(string s) {
        //first technique was 
        //take an character then expand left and right together and try to find the longest substring

        int n=s.size();
        //this technique is the dp on string for palindrome technique

        int maxlen=1;
        int pos=0;
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        //filling the dp array
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j){
                    dp[i][j]=true;//which means all substrings of length 1 are palindromes
                }
            }
        }

        //i+l-1<n
        //so i<n-l+1

        for(int l=2;l<=n;l++){
            for(int i=0;i<n-l+1;i++){
                int j=i+l-1;
                if(s[i]==s[j] && l==2){
                    dp[i][j]=true;
                    maxlen=2;
                    pos=i;
                }else if(s[i]==s[j] && dp[i+1][j-1]){
                    dp[i][j]=true;
                    if(l>maxlen){
                        maxlen=l;
                        pos=i;
                    }
                }

            }
        }
        return s.substr(pos,maxlen);
    }
};