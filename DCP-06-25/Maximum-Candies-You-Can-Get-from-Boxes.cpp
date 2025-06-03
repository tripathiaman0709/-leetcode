class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        //easy question
        //bfs ya dfs lagao

        int n=status.size();

        int ans=0;

        //firstly using bfs

        queue<int>q;
        unordered_set<int>vis;
        unordered_set<int>found;

        for(auto box:initialBoxes){
            found.insert(box);
            if(status[box]==1){
                ans+=candies[box];
                vis.insert(box);
                q.push(box);
            }
        }

        while(!q.empty()){
            int box=q.front();
            q.pop();

            for(auto insidebox:containedBoxes[box]){
                found.insert(insidebox);
                if(status[insidebox]==1 && vis.count(insidebox)==0){
                    q.push(insidebox);
                    vis.insert(insidebox);
                    ans+=candies[insidebox];
                }
            }

            for(auto it:keys[box]){
                status[it]=1;
                if(found.count(it)>0 && vis.count(it)==0){
                    q.push(it);
                    vis.insert(it);
                    ans+=candies[it];
                }
            }
        }
        return ans;
    }
};