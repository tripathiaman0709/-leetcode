class Solution {
public:
    int n,m;
    int dp[51][51][51];

    int fun(int r1,int c1,int c2,vector<vector<int>>&grid){
        n=grid.size();
        m=grid[0].size();

        int r2=r1+c1-c2;

        if(c1<0 || c2<0 || c1>m-1 || c2>m-1 || r1>n-1 || r2>n-1 || grid[r1][c1]==-1 || grid[r2][c2]==-1){
            return -1e8;
        }

        if(dp[r1][c1][c2]!=-1){
            return dp[r1][c1][c2];
        }

        //if one guy reaches the final position the other will also reach the final bottom right corner
        if(r1==n-1 && c1==m-1){
            return grid[r1][c1];
        }
        int ans=grid[r1][c1];
        if(c1!=c2){
            ans+=grid[r2][c2];
        }        
        //total 4 moves possible

        int a=fun(r1,c1+1,c2+1,grid);
        int b=fun(r1+1,c1,c2+1,grid);
        int c=fun(r1,c1+1,c2,grid);
        int d=fun(r1+1,c1,c2,grid);

        int maxi=max({a,b,c,d});

        ans+=maxi;

        return dp[r1][c1][c2]=ans;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        //start se end fir end se start aane se accha hai ki 
        //do logo ko start se bhej do
        //then max calculate ho jaayega

        n=grid.size();
        m=grid[0].size();

        memset(dp,-1,sizeof(dp));

        //trying to return the maximum cherry found along the way

        int ans=fun(0,0,0,grid); 

        return max(0,ans);       
    }
};