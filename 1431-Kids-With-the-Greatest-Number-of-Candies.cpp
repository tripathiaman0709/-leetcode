class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& v, int k) {
        int n=v.size();
        vector<bool>ans(n,false);
        priority_queue<int> pq(v.begin(), v.end());
        int maxi=pq.top();
        for(int i=0;i<n;i++){
            if(v[i]+k>=maxi){
                ans[i]=true;
            }
        }
        return ans;
    }
};