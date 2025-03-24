class Solution {
public:
    int countDays(int k, vector<vector<int>>& v) {
        int n=v.size();
        //merging intervals problem
        sort(v.begin(),v.end());
        int start=v[0][0];
        int end=v[0][1];

        // vector<vector<int>>ans;
        // ans.push_back({start,end});
        int sum=start-1;

        for(int i=1;i<n;i++){
            int nstart=v[i][0];
            int nend=v[i][1];
            if(nstart<=end+1){
                end=max(nend,end);
                // ans.pop_back();
                // ans.push_back({start,end});
            }else{
                sum+=(nstart-end -1);
                start=nstart;
                end=nend;
                // ans.push_back({nstart,nend});
            }
        }
        sum+=(k-end);
        return sum;


        
    }
};