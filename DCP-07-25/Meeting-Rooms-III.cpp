class Solution {
public:
    #define P pair<long long,int> 
    int mostBooked(int n, vector<vector<int>>& v) {
        //easy question using heap
        //implementation is bit lengthy
        sort(v.begin(), v.end());

        vector<int>roomvis(n,0);//initially no room is visited

        priority_queue<P,vector<P>,greater<P>>pq;
        priority_queue<int,vector<int>,greater<int>>rooms;
        //initially no room is visited all empty anyone can be used

        for(int i=0;i<n;i++){
            rooms.push(i);
        }

        for(int i=0;i<v.size();i++){
            int start=v[i][0];
            int end=v[i][1];
            int duration=end-start;

            while(!pq.empty() && start>=pq.top().first){
                int newroom=pq.top().second;
                pq.pop();
                rooms.push(newroom);
            }

            if(!rooms.empty()){
                int room=rooms.top();
                rooms.pop();
                pq.push({end,room});
                roomvis[room]++;
            }else{
                int room=pq.top().second;
                long long endtime=pq.top().first;

                pq.pop();
                pq.push({endtime+duration,room});
                roomvis[room]++;
            }
        }
        int maxi=-1;
        for(int i=0;i<n;i++){
            maxi=max(maxi,roomvis[i]);
        }
        for(int i=0;i<n;i++){
            if(roomvis[i]==maxi){
                return i;
            }
        }
        return -1;
    }
};