class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& v) {
        // int n=v.size();
        // vector<pair<int,int>>vec;
        // for(int i=0;i<n;i++){
        //     int len=v[i][0];
        //     int width=v[i][1];

        //     int diag=len*len + width*width;
        //     vec.push_back({diag,len*width});
        // }
        // int longestdiag=0;
        // for(auto it:vec){
        //     longestdiag=max(longestdiag,it.first);
        // }
        // int ans=0;
        // for(auto it:vec){
        //     if(it.first==longestdiag){
        //         ans=max(ans,it.second);
        //     }
        // }

        // return ans;

        //optimizing this slow ass approach
        //we would be surely need to travel the entire array
        int longestDiagonal=0;
        for(auto it:v){
            longestDiagonal=max(longestDiagonal,(it[0]*it[0] + it[1]*it[1]));
        }
        int ans=0;
        for(auto it:v){
            if(it[0]*it[0] + it[1]*it[1] == longestDiagonal){
                ans=max(ans,(it[0]*it[1]));
            }
        }
        return ans;
    }
};