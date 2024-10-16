class Solution {
public:
    vector<int> findXSum(vector<int>& a, int k, int x) {
        int n=a.size();
        vector<int>ans;
        for(int i=0;i<=n-k;i++){
            vector<pair<int,int>>v;
            vector<int>hash(51,0);
            int sum=0;
            for(int j=i;j<i+k;j++){
                hash[a[j]]++;
            }
            for(int i=1;i<=50;i++){
                v.push_back({hash[i],i});
            }
            sort(v.begin(),v.end());
            for(int i=1;i<=x;i++){
            sum+=v[v.size()-i].first*v[v.size()-i].second;
            }
            ans.push_back(sum);
        }
        return ans;
    }
};