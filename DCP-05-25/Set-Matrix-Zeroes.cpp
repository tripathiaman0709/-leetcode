class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int>r;
        set<int>c;

        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    r.insert(i);
                    c.insert(j);
                }
            }
        }
        vector<int>row;
        vector<int>col;

        for(auto it:r){
            row.push_back(it);
        }
        for(auto it:c){
            col.push_back(it);
        }
        vector<vector<int>>ans(n,vector<int>(m,-1));
        /*sort(row.begin(),row.end());
        sort(col.begin(),col.end());

        
        
        for(int i=0;i<n;i++){
            if(binary_search(col.begin(), row.end(), i)){
                continue;
            }else{
            for(int j=0;j<m;j++){
                if(binary_search(col.begin(), col.end(), j)){
                    continue;
                }else{
                    ans[i][j]=matrix[i][j];
                }
            }
            }
        }*/
        
        for(int i=0;i<row.size();i++){
            int x=row[i];
            for(int j=0;j<m;j++){
                ans[x][j]=0;
            }
        }

        for(int i=0;i<col.size();i++){
            int y=col[i];
            for(int j=0;j<n;j++){
                ans[j][y]=0;
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(ans[i][j]==-1){
                    ans[i][j]=matrix[i][j];
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                matrix[i][j]=ans[i][j];
            }
        }
    }
};