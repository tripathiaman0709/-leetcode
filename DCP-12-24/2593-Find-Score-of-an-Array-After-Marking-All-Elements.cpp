class Solution {
public:
    #define p pair<int,int>
    long long findScore(vector<int>& v) {
        int n=v.size();
        //solving it using max heap of pairs of number and index
        priority_queue<p,vector<p>,greater<p>>pq;

        for(int i=0;i<n;i++){
            pq.push({v[i],i});
        }
        long long sum=0;
        vector<bool>vis(n,false);
        while(!pq.empty()){
            int x=pq.top().first;
            int y=pq.top().second;
            pq.pop();
            if(vis[y]){
                continue;
            }else{
                sum+=x;
                vis[y]=true;
                if(y-1>=0){
                    vis[y-1]=true;
                }
                if(y+1<n){
                    vis[y+1]=true;
                }
            }
        }
        return sum;
    }
};