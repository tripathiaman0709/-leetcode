class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extra) {
        //priority queue use hogi
        //sab me increment krke dekho 
        //jiska max hai usko badhao

        int n=classes.size();
        priority_queue<pair<double,int>,vector<pair<double,int>>>pq;
        //creating a max heap
        for(int i=0;i<n;i++){
            int pass=classes[i][0];
            int total=classes[i][1];

            double originalRatio=double(pass)/double(total);
            double newRatio=double(pass+1)/double(total+1);
            double diff=newRatio-originalRatio;
            pq.push({diff,i});
        }

        while(extra--){
            auto it=pq.top();
            pq.pop();

            int ind=it.second;

            classes[ind][0]++;
            classes[ind][1]++;

            int pass=classes[ind][0];
            int total=classes[ind][1];

            double originalRatio=double(pass)/double(total);
            double newRatio=double(pass+1)/double(total+1);
            double diff=newRatio-originalRatio;
 

            pq.push({diff,ind});
        }
        double ans=0;
        for(int i=0;i<n;i++){
            ans+=double(classes[i][0])/double(classes[i][1]);
        }

        ans/=n;

        return ans;
    }
};