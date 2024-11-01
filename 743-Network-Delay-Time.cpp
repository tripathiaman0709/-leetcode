class Solution {
public:
    int networkDelayTime(vector<vector<int>>& arr, int n, int k) {
        //firstly making an adjacency list
        //using map
        unordered_map<int,vector<pair<int,int>>>mpp;
        for(int i=0;i<arr.size();i++){
            int wt =arr[i][2];
            int a  =arr[i][0];
            int b  =arr[i][1];

            mpp[a].push_back({b,wt});
        }
        vector<int>v(n+1,INT_MAX);
        //now making in a priority queue
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});
        v[k]=0;
        //needed 0 distance to reach to node k

        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();

            int wt=it.first;
            int node=it.second;

            for(auto it:mpp[node]){
                int wt2=it.second;
                int node2=it.first;

                if(wt+wt2 < v[node2]){
                    v[node2]=wt+wt2;
                    pq.push({wt+wt2,node2});
                }
            }
        }

        int maxi=INT_MIN;
        for(int i=1;i<=n;i++){            
            maxi=max(maxi,v[i]);
        }
        if(maxi==INT_MAX){
            return -1;
        }else{
            return maxi;
        }
    }
};