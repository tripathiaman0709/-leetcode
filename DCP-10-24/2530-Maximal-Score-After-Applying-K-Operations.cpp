class Solution {
public:
    long long maxKelements(vector<int>& a, int k) {
        int n=a.size();
        priority_queue<int,vector<int>>pq;
        //biggest element will be at top

        for(int i=0;i<n;i++){
            pq.push(a[i]);
        }
        long long sum=0;
        while(k--){
            int x=pq.top();
            pq.pop();
            sum+=x;
            pq.push((x+2)/3);
        }
        return sum;
    }
};