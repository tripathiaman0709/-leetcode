class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& grid) {
        unordered_set<string>st;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                //pehle row se match kro
                //fir column se match kro
                //fir within the 3x3 grid ko match kro
                if(grid[i][j]=='.'){
                    continue;
                }
                int boxi=i/3;
                int boxj=j/3;
                string row="row";
                row+=i;
                row+=grid[i][j];
                string col="col";
                col+=j;
                col+=grid[i][j];
                string box="box";
                box+=boxi;
                box+=boxj;
                box+=grid[i][j];

                if(st.find(row)!=st.end() || st.find(col)!=st.end() || st.find(box)!=st.end()){
                    return false;
                }

                st.insert(row);
                st.insert(col);
                st.insert(box);
            }
        }
        return true;
    }
};