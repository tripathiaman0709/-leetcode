class Solution {
public:
    int longestSquareStreak(vector<int>& a) {
        int n=a.size();
        sort(a.begin(),a.end());
        unordered_map<int,int>mpp;
        mpp[a[0]]=1;
        int maxi=0;
        for(int i=1;i<n;i++){
            int root=sqrt(a[i]);
            if(root*root==a[i] && mpp.count(root)){
                mpp[a[i]]=mpp[root]+1;
            }else{
                mpp[a[i]]=1;
            }
            maxi=max(maxi,mpp[a[i]]);
        }
        if(maxi<2){
            return -1;
        }else{
            return maxi;
        }
    }
};