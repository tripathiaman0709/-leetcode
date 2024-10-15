class Solution {
public:
    long long minimumSteps(string s) {
        long n=s.size();

        long ans=0;
        long i=0,j=n-1;

        while(i<j){
            while(i<j && s[i]!='1') i++;
            while(i<j && s[j]!='0') j--;

            if(i<j && s[i]=='1' && s[j]=='0'){
                ans+=(j-i);
                i++;
                j--;
            }
        }
        return ans;
    }
};