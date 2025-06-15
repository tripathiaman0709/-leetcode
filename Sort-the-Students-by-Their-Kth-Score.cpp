class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        int n=score.size();
        int m=score[0].size();

        vector<pair<int,int>>v;

        for(int i=0;i<n;i++){
            v.push_back({score[i][k],i});
        }

        sort(v.rbegin(),v.rend());

        vector<vector<int>>ans=score;

        for(int i=0;i<n;i++){
            int row=v[i].second;
            for(int j=0;j<m;j++){
                ans[i][j]=score[row][j];
            }
        }

        return ans;

    }
};