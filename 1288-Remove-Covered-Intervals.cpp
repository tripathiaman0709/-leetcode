class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& v) {
        //can use a double for loop 
        int n=v.size();
        for(int i=0;i<n;i++){
            int start=v[i][0];
            int end=v[i][1];

            for(int j=0;j<n;j++){
                int curstart=v[j][0];
                int curend=v[j][1];

                if(j==i)continue;

                if(curstart>=start && curend<=end){
                    v[j][0]=-1;
                    v[j][1]=-1;
                }

            }
        }

        int count=0;

        for(int j=0;j<n;j++){
                int curstart=v[j][0];
                int curend=v[j][1];

                if(curstart==-1){
                    count++;
                }
        }

        return n-count;
    }
};