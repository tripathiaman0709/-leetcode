class Solution {
public:

    int maximumProduct(vector<int>& v) {
        //finding three maximum digits of the number then numtiplying
        int n=v.size();
        sort(v.begin(),v.end());

        int neg=v[0]*v[1];
        neg*=v[n-1];

        int pos=v[n-1]*v[n-2]*v[n-3];

        int ans=max(pos,neg);

        return ans;
    }
};
