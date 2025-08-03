class Solution {
public:
    vector<vector<int>> generate(int r) {
        vector<int>curr(1,1);
        vector<vector<int>>ans;
        ans.push_back(curr);
        while(r>1){
            vector<int>newcurr(curr.size()+1,1);
            for(int i=1;i<curr.size();i++){
                newcurr[i]=curr[i-1]+curr[i];
            }
            ans.push_back(newcurr);
            curr=newcurr;
            r--;
        }
        return ans;
    }
};