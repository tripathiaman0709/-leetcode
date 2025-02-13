class Solution {
public:
    int minOperations(vector<int>& v, int k) {
        //always taking two smallest numbers and adding a new number

        int n=v.size();
        priority_queue<long long,vector<long long>,greater<>>pq;
        for(int i=0;i<n;i++){
            pq.push(v[i]);
        }
        int count=0;

        if(pq.top()>=k){
            return 0;
        }

        while(1){   
            long long x=pq.top();
            pq.pop();
            long long y=pq.top();
            pq.pop();
            long long z=min(x,y)*2+max(x,y);
            count++;
            pq.push(z);

            if(pq.top()>=k){
                break;
            }            
        }
        return count;
    }
};