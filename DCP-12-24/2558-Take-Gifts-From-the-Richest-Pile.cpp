class Solution {
public:
    long long pickGifts(vector<int>& v, int k) {
        int n=v.size();
        priority_queue<int,vector<int>>pq;
        for(int i=0;i<n;i++){
            pq.push(v[i]);
        }
        long long sum=0;

        while(k--){
            int x=pq.top();
            pq.pop();
            int sq=sqrt(x);
            pq.push(sq);
        }

        while(!pq.empty()){
            sum+=pq.top();
            pq.pop();
        }
        return sum;
    }
};