class Solution {
public:
    bool check(vector<int>& v) {
        int n=v.size();
        // vector<int>sorted=v;
        // sort(sorted.begin(),sorted.end());
        // //just one simple way 
        // //ima just brute forcing

        // for(int i=0;i<n;i++){
        //     vector<int>ans;
        //     for(int j=i;j<n;j++){
        //         ans.push_back(v[j]);
        //     }
        //     for(int j=0;j<i;j++){
        //         ans.push_back(v[j]);
        //     }

        //     if(ans==sorted){
        //         return true;
        //     }
        // }
        // return false;


        //now instead of O(n^2)
        //going for more optimal solution
        int mini=101;
        int minipos=0;
        for(int i=0;i<n;i++){
            if(v[i]<mini){
                mini=v[i];
                minipos=i;
            }
        }
        int mini1=101;
        int minipos1=0;
        for(int i=n-1;i>=0;i--){
            if(v[i]==mini){
                minipos1=i;
            }else{
                break;
            }
        }
        //now we got the position of the minimum or smallest element

        vector<int>ans;
        for(int i=minipos;i<n;i++){
            ans.push_back(v[i]);
        }
        for(int i=0;i<minipos;i++){
            ans.push_back(v[i]);
        }
        vector<int>ans1;
        for(int i=minipos1;i<n;i++){
            ans1.push_back(v[i]);
        }
        for(int i=0;i<minipos1;i++){
            ans1.push_back(v[i]);
        }
        int p=1;
        int q=1;
        for(int i=0;i<n-1;i++){
            if(ans[i]>ans[i+1]){
                p=0;
                break;
            }
        }
        for(int i=0;i<n-1;i++){
            if(ans1[i]>ans1[i+1]){
                q=0;
                break;
            }
        }
        if(p+q>0){
            return true;
        }
        return false;
        
    }
};