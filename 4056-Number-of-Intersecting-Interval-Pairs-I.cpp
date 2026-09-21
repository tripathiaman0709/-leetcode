class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& v) {
        int n=v.size();
        sort(v.begin(),v.end());

        // int start=v[0][0];
        // int end=v[0][1];

        vector<int>start;
        for(int i=0;i<n;i++){
            start.push_back(v[i][0]);
        }
        
        int sum=0;

        for(int i=0;i<n;i++){
            int s=v[i][0];
            int e=v[i][1];

            auto it=upper_bound(start.begin(),start.end(),e)-start.begin();
            sum+=(it-i-1);
        }
        return sum;
    }
};