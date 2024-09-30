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

    int fun(int i,int pre,vector<string>&a,int n){
        if(i==n){
            return 0;
        }
        if(pre!=-1 && dp[i][pre]!=-1){
            return dp[i][pre];
        }
        int take=0;
        int nottake=0;

        if(pre==-1 || check(a[pre],a[i])){
            take=1+fun(i+1,i,a,n);
        }
        nottake=fun(i+1,pre,a,n);
        if(pre!=-1){
            return dp[i][pre]=max(take,nottake);
        }
        return max(take,nottake);
    }

    static bool comp(string &s1, string &s2){
        return s1.size()<s2.size();
    }

    int longestStrChain(vector<string>& a) {
        int n=a.size();
        memset(dp,-1,sizeof(dp));
        //sorting by the length of the strings
        sort(a.begin(),a.end(),comp);
        //doing recurrsion then memoization then finally tabulation or bottom up approach

        return fun(0,-1,a,n);
    }
};