class Solution {
public:
    vector<int> kahn(vector<vector<int>>& cond,int k){
        vector<int> indegree(k,0);
        vector<vector<int>>adj(k+1);
        for(auto row:cond){
            adj[row[0]].push_back(row[1]);
            indegree[row[1]-1]++;
        }
        queue<int>q;
        vector<int> ans;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0){
                q.push(i+1);
            }
        }
        while(!q.empty()){
            int front=q.front();q.pop();
            ans.push_back(front);
            for(auto nbr:adj[front]){
                indegree[nbr-1]--;
                if(indegree[nbr-1]==0)q.push(nbr);
            }

        }
        return ans;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        //top sorted order using kahn algorithm
        vector<int> row_order=kahn(rowConditions,k);
        vector<int> col_order=kahn(colConditions,k);
        //checking for cycle
        if(row_order.size()<k || col_order.size()<k)return {};
        //creating a column order map for easy access
        unordered_map <int,int> colmp;
        for(int i=0;i<col_order.size();i++){
            colmp[col_order[i]]=i;
        }
        //creating the answer matrix
        vector<vector<int>>ans(k,vector<int>(k,0));
        for (int i = 0; i < row_order.size(); ++i) {
            int num = row_order[i];        // the number that must live in row i
            int col = colmp[num];          // the column it must live in
            ans[i][col] = num;             // place it
        }

        return ans;
    }
};