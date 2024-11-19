class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& v, vector<int>& p) {
        int n=v.size();
        vector<int>start(n,0);
        vector<int>end(n,0);

        for(int i=0;i<n;i++){
            int first=v[i][0];
            int second=v[i][1];

            start[i]=first;
            end[i]=second;
        }

        sort(start.begin(),start.end());
        sort(end.begin(),end.end());

        vector<int>ans;

        for(int i=0;i<p.size();i++){
            //kitne phool p[i] se pehle ya equal pe khile hai
            int pos=p[i];
            int s=upper_bound(start.begin(),start.end(),pos)-start.begin();
            //kitne phool mar chuke hai
            int e=lower_bound(end.begin(),end.end(),pos)-end.begin();

            ans.push_back(s-e);
        }

        return ans;
    }
};