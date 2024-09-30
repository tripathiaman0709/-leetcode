class Solution {
public:

    int dp[1001][1001];

    bool check(string &s1,string &s2){
        int n=s1.size();
        int m=s2.size();

        if(n>=m || (m-n)!=1){
            return false;
        }
        int i=0;
        int j=0;

        while(i<n && j<m){
            if(s1[i]==s2[j]){
                i++;
            }
            j++;
        }
        if(i==n){
            return true;
        }
        return false;
    }

    static bool comp(string &s1, string &s2){
        return s1.size()<s2.size();
    }

    int longestStrChain(vector<string>& a) {
        int n=a.size();
        //sorting by the length of the strings
        sort(a.begin(),a.end(),comp);
        vector<int>v(n,1);
        int maxi=1;
        //doing recurrsion then memoization then finally tabulation or bottom up approach
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(check(a[j],a[i])){
                    v[i]=max(v[i],1+v[j]);
                    maxi=max(maxi,v[i]);
                }
            }
        }
        return maxi;


    }
};