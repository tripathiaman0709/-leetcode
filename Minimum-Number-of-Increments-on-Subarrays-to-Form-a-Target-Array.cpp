class Solution {
public:
    int minNumberOperations(vector<int>& v) {
        int n=v.size();
        int ans=v[0];

        for(int i=1;i<n;i++){
            if(v[i]>v[i-1]){
                ans+=(v[i]-v[i-1]);
            }
        }
        return ans;
    }
};