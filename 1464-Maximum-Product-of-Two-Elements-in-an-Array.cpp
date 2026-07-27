class Solution {
public:
    int maxProduct(vector<int>& v) {
        int n=v.size();
        sort(v.rbegin(),v.rend());

        int ans=(v[0]-1)*(v[1]-1);
        return ans;
    }
};