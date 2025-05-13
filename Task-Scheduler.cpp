class Solution {
public:
    int leastInterval(vector<char>& v, int k) {
        int n=v.size();
        vector<int>hash(26,0);
        //using priority queue
        priority_queue<int>pq;
        //max heap gets generated

        for(int i=0;i<n;i++){
            hash[v[i]-'A']++;
        }

        for(int i=0;i<26;i++){
            if(hash[i]>0){
                pq.push(hash[i]);
            }
        }
        int time=0;
        while(!pq.empty()){
            vector<int>temp;
            for(int i=1;i<=k+1;i++){
                if(!pq.empty()){
                    int freq=pq.top();
                    freq--;
                    pq.pop();
                    temp.push_back(freq);
                }
            }
            for(auto it:temp){
                if(it>0){
                    pq.push(it);
                }
            }

            if(pq.empty()){
                time+=temp.size();
            }else{
                time+=k+1;
            }
        }

        return time;
    }
};