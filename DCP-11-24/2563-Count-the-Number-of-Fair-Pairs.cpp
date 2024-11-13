class Solution {
public:
    long long countFairPairs(vector<int>& v, int low, int high) {
        int n=v.size();
        long long count=0;
        sort(v.begin(),v.end());
        //looks like need the use of upper bound and lower bound

        for(int i=0;i<n;i++){
            int x=high-v[i];
            int y=low-v[i];

            int a=lower_bound(v.begin()+i+1,v.end(),y)-v.begin()-1;
            int b=upper_bound(v.begin()+i+1,v.end(),x)-v.begin()-1;

            count+=(b-a);
        }
        return count;
    }
};