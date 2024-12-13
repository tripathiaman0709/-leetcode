class Solution {
public:
    long long findScore(vector<int>& v) {
        int n=v.size();
        vector<pair<int,int>>a;
        for(int i=0;i<n;i++){
            a.push_back({v[i],i});
        }
        sort(a.begin(),a.end());
        vector<bool>vis(n,false);
        long long sum=0;
        for(int i=0;i<n;i++){
            if(vis[a[i].second]){
                continue;
            }else{
                sum+=a[i].first;
                vis[a[i].second]=true;
                if(a[i].second - 1 >=0){
                    vis[a[i].second - 1]=true;
                }
                if(a[i].second + 1 <n){
                    vis[a[i].second + 1]=true;
                }
            }
        }
        return sum;
    }
};