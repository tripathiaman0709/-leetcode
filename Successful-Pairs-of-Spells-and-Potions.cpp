class Solution {
public:
    vector<int> successfulPairs(vector<int>& v1, vector<int>& v2, long long k) {
        sort(v2.begin(),v2.end());
        vector<int>ans;
        int sz=v2.size();
        for(int i=0;i<v1.size();i++){
            long long a=v1[i];

            long long b=(k+a-1)/a;

            auto it=lower_bound(v2.begin(),v2.end(),b)-v2.begin();
            if(it==sz){
                ans.push_back(0);
            }else{
               ans.push_back(sz-it);
            }   
        }

        return ans;

    }
};