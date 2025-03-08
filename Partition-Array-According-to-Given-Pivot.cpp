class Solution {
public:
    vector<int> pivotArray(vector<int>& v, int p) {
        //solving it in a simple way
        //without using the pivot element technique

        vector<int>small;
        vector<int>large;
        vector<int>equal;
        vector<int>ans;
        
        int n=v.size();
        for(int i=0;i<n;i++){
            if(v[i]<p){
                small.push_back(v[i]);
            }else if(v[i]>p){
                large.push_back(v[i]);
            }else{
                equal.push_back(v[i]);
            }
        }
        for(auto it:small){
            ans.push_back(it);
        }
        for(auto it:equal){
            ans.push_back(it);
        }
        for(auto it:large){
            ans.push_back(it);
        }
        return ans;
    }
};