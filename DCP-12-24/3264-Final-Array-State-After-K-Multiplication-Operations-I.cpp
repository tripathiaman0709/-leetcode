class Solution {
public:
    vector<int> getFinalState(vector<int>& v, int k, int m) {
        int n=v.size();
        priority_queue<int,vector<int>,greater<int>>pq;//min heap
        for(int i=0;i<n;i++){
            pq.push(v[i]);
        }
        for(int i=0;i<k;i++){
            int x=pq.top();
            pq.pop();
            for(int j=0;j<n;j++){                
                if(v[j]==x){
                    v[j]*=m;
                    pq.push(v[j]);
                    break;
                }
            }
        }
        return v;
    }
};