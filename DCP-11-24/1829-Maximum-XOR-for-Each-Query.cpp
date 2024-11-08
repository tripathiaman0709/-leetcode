class Solution {
public:
    vector<int> getMaximumXor(vector<int>& v, int maximumBit) {
        int n=v.size();
        int x=0;
        for(int i=0;i<n;i++){
            x^=v[i];
        }
        //now finding k
        int k=((1<<maximumBit)-1);
        vector<int>res;
        for(int i=0;i<n;i++){
            int ans=x^k;
            res.push_back(ans);
            x^=v[n-i-1];
        }
        return res;
    }
};