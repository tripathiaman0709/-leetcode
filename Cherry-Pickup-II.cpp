class Solution {
public:
    int n,m;
    int dp[71][71][71];

    int fun(int r,int c1,int c2,vector<vector<int>>&grid){
        n=grid.size();
        m=grid[0].size();
        //checking out of bounds
        if(r>n-1 || c1>m-1 || c2>m-1 || c1<0 || c2<0){
            return -1e8;
        }
        if(r==n-1){
            if(c1==c2){
                return grid[r][c1];
            }else{
                return grid[r][c1]+grid[r][c2];
            }
        }

        if(dp[r][c1][c2]!=-1){
            return dp[r][c1][c2];
        }

        //now total 9 moves can be performed
        int maxi=0;
        for(int d1=-1;d1<=1;d1++){
            int nc1=c1+d1;
            for(int d2=-1;d2<=1;d2++){
                int nr=r+1;
                int nc2=c2+d2;

                int val=fun(r+1,nc1,nc2,grid);                

                if(c1==c2){
                    val+=grid[r][c1];
                }else{
                    val+=grid[r][c1]+grid[r][c2];
                }

                maxi=max(maxi,val);
            }
        }

        return dp[r][c1][c2]=maxi;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        memset(dp, -1, sizeof(dp));

        //simple recursion hai
        //dono robots ko move krao
        //offlimits jaane pe and last row pe pahuchne vala hoga base case

        //return krna hai maximum candies jo dono ne collect kri hai
        //agr dono ek hi block pe then counting once only
        //else dono ko seperate count karo

        //row number will be same for both as the row number increases on each step


        int ans=fun(0,0,m-1,grid);

        return ans;
    }
};