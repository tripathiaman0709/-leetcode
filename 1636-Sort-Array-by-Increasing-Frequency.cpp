class Solution {
public:

    static bool comp(pair<int,int> &a, pair<int,int> &b){
        if(a.first == b.first){
            return a.second > b.second;
        }
        return a.first < b.first;
    }

    vector<int> frequencySort(vector<int>& a) {
        int n=a.size();
        map<int,int>mpp;
        for(int i=0;i<n;i++){
            mpp[a[i]]++;
        }


        vector<pair<int,int>>v; 

        for(auto it:mpp){
            int x=it.first;
            int y=it.second;
            v.push_back({y,x});
        }
        sort(v.begin(),v.end(),comp);

        vector<int>ans;

        for(int i=0;i<v.size();i++){
            int freq=v[i].first;
            int num=v[i].second;

            for(int j=0;j<freq;j++){
                ans.push_back(num);
            }
        }

        return ans;
    }
};