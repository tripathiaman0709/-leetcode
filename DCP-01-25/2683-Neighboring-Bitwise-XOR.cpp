class Solution {
public:
    bool doesValidArrayExist(vector<int>& v) {
        int n=v.size();
        int xoro=0;
        for(int i=0;i<n;i++){
            xoro^=v[i];
        }
        if(xoro){
            return false;
        }
        return true;
    }
};