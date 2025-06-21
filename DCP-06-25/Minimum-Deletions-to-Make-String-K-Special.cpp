class Solution {
public:
    int minimumDeletions(string s, int k) {
        int n=s.size();

        unordered_map<char,int>mpp;
        for(int i=0;i<n;i++){
            mpp[s[i]]++;
        }
        vector<int>v;

        for(auto it:mpp){
            v.push_back(it.second);
        }

        sort(v.begin(),v.end());
        int mini=n;
        for(int i=0;i<v.size();i++){
            int del=0;
            for(int j=0;j<v.size();j++){
                if(v[j]<v[i]){
                    del+=v[j];
                }
                if((v[j]-v[i])>k){
                    del+=((v[j]-v[i])-k);
                }
            }
            mini=min(mini,del);
        }

        return mini;
    }
};