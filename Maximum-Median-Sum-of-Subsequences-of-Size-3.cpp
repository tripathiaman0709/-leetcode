class Solution {
public:
    long long maximumMedianSum(vector<int>& v) {
        int n=v.size();
        sort(v.begin(),v.end());

        int i=0;
        int j=n-1;

        long long sum=0;

        while(i<j){
            sum+=v[j-1];
            j-=2;
            i++;
        }

        return sum;
    }
};