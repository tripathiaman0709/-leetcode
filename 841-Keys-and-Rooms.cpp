class Solution {
public:

    void dfs(vector<vector<int>>& rooms,int source,vector<bool>&v){
        v[source]=true;
        for(auto it:rooms[source]){
            if(!v[it]){
                dfs(rooms,it,v);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool>v(n,false);//visited vector

        dfs(rooms,0,v);

        for(auto it:v){
            if(!it){
                return false;
            }
        }
        return true;

    }
};