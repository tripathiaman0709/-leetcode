class Solution {
public:
    int count=0;

    bool check(int row,int col,vector<vector<int>>&v){
        int n=v.size();
        for(int i=row;i>=0;i--){
            if(v[i][col]==1){
                return false;
            }
        }
        
        for(int i=row,j=col;i>=0 && j<n;i--,j++){
            if(v[i][j]==1){
                return false;
            }
        }
        for(int i=row,j=col;i>=0 && j>=0;i--,j--){
            if(v[i][j]==1){
                return false;
            }
        }

        return true;

    }

    void solve(int row,vector<vector<int>>&v){
        int n=v.size();
        if(row == n){
            count++;
            return;
        }

        //select
        //traverse
        //undo

        for(int i=0;i<n;i++){
            if(check(row,i,v)){
                v[row][i]=1;
                solve(row+1,v);
                v[row][i]=0;
            }
        }
    }

    int totalNQueens(int n) {
        //checking if the move is correct
        vector<vector<int>>v(n,vector<int>(n,0));
        solve(0,v);

        return count;
    }
};