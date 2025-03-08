class Solution {
public:
    int minimumRecolors(string s, int k) {
        int n=s.size();
        int mini=100001;
        //runnig a n*k loop
        int count=0;
        for(int i=0;i<=n-k;i++){
            count=0;
            for(int j=i;j<i+k;j++){
                if(s[j]=='W'){
                    count++;
                }
            }
            mini=min(mini,count);
        }
        return mini;
    }
};