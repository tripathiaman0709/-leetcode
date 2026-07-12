class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& v) {
        int n=v.size();
        if(n==0){
            return {};
        }
        
        map<int,int>mpp;
        vector<int>sorted=v;
        sort(sorted.begin(),sorted.end());
        int count=1;
        mpp[sorted[0]]=count;
        for(int i=1;i<n;i++){
            if(sorted[i]!=sorted[i-1]){
                count++;
            }
            mpp[sorted[i]]=count;
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            ans.push_back(mpp[v[i]]);
        }

        return ans;
    }
};