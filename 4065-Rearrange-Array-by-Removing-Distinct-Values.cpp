class Solution {
public:
    vector<int> rearrangeArray(vector<int>& v) {
        int n=v.size();
        vector<int>ans;
        map<int,int>mpp;

        for(int i=0;i<n;i++){
            mpp[v[i]]++;
        }
        int count=0;
        while(count<n){
            for(auto it:mpp){
                if(mpp[it.first]>0){
                    ans.push_back(it.first);
                    count++;
                    mpp[it.first]--;
                }
            }
        }
        return ans;
    }
};