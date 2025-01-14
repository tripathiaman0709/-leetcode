class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& v1, vector<int>& v2) {
        //trying the easy way
        int n=v1.size();
        vector<int>ans(n,0);
        int count=0;
        set<int>s;
        for(int i=0;i<n;i++){
            s.insert(v1[i]);
            s.insert(v2[i]);
            count+=2;
            int x=s.size();

            ans[i]=count-x;            
        }
        return ans;
    }
};