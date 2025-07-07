class Solution {
public:
    int maxEvents(vector<vector<int>>& v) {
        int n=v.size();
        sort(v.begin(),v.end());
        int start=v[0][0];
        int i=0;
        int count=0;
        priority_queue<int,vector<int>,greater<int>>pq;//min heap

        while(!pq.empty() || i<n){
            while(i<n && start==v[i][0]){
                pq.push(v[i][1]);
                i++;
            }
            if(!pq.empty()){
                pq.pop();
                count++;
            }
            start++;
            while(!pq.empty() && pq.top()<start){
                pq.pop();
            }
        }
        return count;
    }
};