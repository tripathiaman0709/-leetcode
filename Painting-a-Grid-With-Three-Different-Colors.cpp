class Solution {
public:
    vector<string>col;
    vector<vector<int>>dp;
    vector<char>v={'R','G','B'};
    int M=1e9+7;

    void gen(string curr,char prev,int l,int n){
        if(l>=n){
            col.push_back(curr);
            return;
        }

        for(int i=0;i<3;i++){
            char ch=v[i];
            if(ch==prev){
                continue;
            }
            gen(curr+ch,ch,l+1,n);
        }
    }

    int solve(int remaining,int prev,int n){
        //base case
        if(remaining==0){
            return 1;
        }
        if(dp[remaining][prev]!=-1){
            return dp[remaining][prev];
        }
        int ways=0;
        string prevstate=col[prev];

        for(int i=0;i<col.size();i++){
            if(i==prev){
                continue;
            }
            string currstate=col[i];
            bool valid=true;

            for(int j=0;j<n;j++){
                if(prevstate[j]==currstate[j]){
                    valid=false;
                    break;
                }
            }
            if(valid){
                ways=(ways+solve(remaining-1,i,n))%M;
            }
        }
        return dp[remaining][prev]=ways;
    }

    int colorTheGrid(int n, int m) {
        //generating all the possible states that can be formed in the column
        
        gen("",'?',0,n);

        //now all the states are generated
        int ans=0;
        dp=vector<vector<int>>(m+1,vector<int>(col.size()+1,-1));

        for(int i=0;i<col.size();i++){
            ans=(ans+solve(m-1,i,n))%M;
        }

        return ans;

    }
};