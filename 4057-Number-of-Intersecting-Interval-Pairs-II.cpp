class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& v) {
        int n=v.size();
        sort(v.begin(),v.end());

        // int start=v[0][0];
        // int end=v[0][1];

        vector<long long>start;
        for(long long i=0;i<n;i++){
            start.push_back(v[i][0]);
        }
        
        long long sum=0;

        for(long long i=0;i<n;i++){
            long long s=v[i][0];
            long long e=v[i][1];

            auto it=upper_bound(start.begin(),start.end(),e)-start.begin();
            sum+=(it-i-1);
        }
        return sum;
    }
};