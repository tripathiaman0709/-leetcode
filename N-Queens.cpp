class Solution {
public:
    vector<vector<string>>ans;
    bool isvalid(int row,int col,vector<string>&v){
        //checking up
        for(int i=row-1;i>=0;i--){
            if(v[i][col]=='Q'){
                return false;
            }
        }
        //checking upper right diagonal
        for(int i=row-1, j=col-1;i>=0 && j>=0;i--, j--){
            if(v[i][j]=='Q'){
                return false;
            }
        }
        //checking upper left diagonal
        for(int i=row-1,j=col+1;i>=0 && j<v.size();i--,j++){
            if(v[i][j]=='Q'){
                return false;
            }
        }
        return true;
    }

    void solve(vector<string>&v,int row){
        if(row>=v.size()){
            ans.push_back(v);
            return;
        }
        for(int i=0;i<v.size();i++){
            if(isvalid(row,i,v)){
                //do
                v[row][i]='Q';
                //explore
                solve(v,row+1);
                //undo
                v[row][i]='.';
            }
        }

    }
    vector<vector<string>> solveNQueens(int n) {
        //its a simple recursion + backtracking problem
        vector<string>v(n,string(n,'.'));
        //firstly solving using isvalid function 
        //then solving by effiecient approach of using unordered set
        solve(v,0);

        return ans;
    }
};