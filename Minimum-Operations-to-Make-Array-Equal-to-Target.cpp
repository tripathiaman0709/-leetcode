class Solution {
public:
    long long minimumOperations(vector<int>& v, vector<int>& t) {
        int n=v.size();

        vector<int>diff;
        diff.push_back(0);

        for(int i=0;i<n;i++){
            diff.push_back(t[i]-v[i]);
        }

        long long ans=0;

        for(int i=1;i<=n;i++){
            int prev=diff[i-1];
            int curr=diff[i];

            if(prev>0 && curr<0){
                //sign change
                ans+=abs(curr);
            }
            else if(prev<0 && curr>0){
                 //sign change
                ans+=abs(curr);
            }
            else if(abs(curr)>abs(prev)){
                ans+=abs(curr)-abs(prev);
            }
        }

        return ans;
    }
};