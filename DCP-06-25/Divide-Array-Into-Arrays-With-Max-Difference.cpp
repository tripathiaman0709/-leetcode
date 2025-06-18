class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& v, int k) {
        int n=v.size();
        vector<vector<int>>empty;
        vector<vector<int>>ans(n/3,vector<int>(3,0));

        sort(v.begin(),v.end());

        for(int i=0;i<n-2;i+=3){
            if(v[i+2]-v[i]>k){
                return empty;
            }
        }
        int row=0;
        for(int i=0;i<n-2;i+=3){
            ans[row][0]=v[i];
            ans[row][1]=v[i+1];
            ans[row][2]=v[i+2];
            row++;
        }

        return ans;
    }
};