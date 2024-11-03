class Solution {
public:
    vector<int> minOperations(string s) {
        int n=s.size();
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            v.push_back({s[i]-48,i});
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
                int sum=0;
                for(int j=0;j<n;j++){
                    if(v[j].first==1){
                        sum+=abs(i-j);
                    }
                }
                ans.push_back(sum);
        }
        return ans;
    }
};