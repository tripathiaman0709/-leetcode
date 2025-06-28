class Solution {
public:
    vector<int> maxSubsequence(vector<int>& v, int k) {
        int n=v.size();
        vector<pair<int,int>>vec;
        for(int i=0;i<n;i++){
            vec.push_back({v[i],i});
        }

        sort(vec.rbegin(),vec.rend());

        vector<pair<int,int>>vv;

        for(int i=0;i<k;i++){
            int ind=vec[i].second;
            int num=vec[i].first;

            vv.push_back({ind,num});
        }

        sort(vv.begin(),vv.end());

        vector<int>ans;

        for(int i=0;i<vv.size();i++){
            ans.push_back(vv[i].second);
        }

        return ans;
    }
};