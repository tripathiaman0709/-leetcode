class Solution {
public:

    long long M=1e9+7;

    int countTrapezoids(vector<vector<int>>& v) {
        //we know that slope is y2-y1 / x2-x1
        //and we need equal slopes 
        //and need to be horizontal as well
        //ie slope is 0
        //y2-y1 = 0

        int n=v.size();
        unordered_map<int,int>mppy;

        for(int i=0;i<n;i++){
            int y=v[i][1];
            mppy[y]++;
        }

        for(auto &it:mppy){
            int x=it.second;
            int val = (1LL * x * (x - 1) / 2) % M;

            it.second=val;
        }

        long long total=0;
        long long ans=0;

        for(auto it:mppy){
            int y=it.second;
            ans+=y*total;
            ans%=M;
            total+=y;
            total%=M;
        }

        return (int)ans;
    }
};