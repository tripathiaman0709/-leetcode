class Solution {
public:
    vector<vector<int>>ans;
    void fun(int start,int k,int n,vector<int>&v){
        if(v.size()==n){
            if(k==0){
                ans.push_back(v);
                return;
            }
            return;            
        }
        //backtraking
        //do explore and undo
        for(int i=start;i<10;i++){
            v.push_back(i);
            fun(i+1,k-i,n,v);
            v.pop_back();
        }

    }

    vector<vector<int>> combinationSum3(int n, int k) {
        //here k elements ko leke n sum banana hai
        vector<int>v;
        fun(1,k,n,v);

        return ans;
    }
};