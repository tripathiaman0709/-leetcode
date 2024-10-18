class Solution {
public:
vector<int>v;
    void fun(int ind,vector<int>&a,int n,map<int,int>&mpp){
        
        if(ind==n){
            int x=0;
            for(int i=0;i<v.size();i++){
                x|=v[i];
            }
            mpp[x]++;
        }
        else{
        v.push_back(a[ind]);
        fun(ind+1,a,n,mpp);
        v.pop_back();
        fun(ind+1,a,n,mpp);
        }
    }

    int countMaxOrSubsets(vector<int>& a) {
        int n=a.size();
        //generating all possible subsets and fnding OR then counting the ones with the maximum OR
        //--> Brute Force approach
        //could map the value with the subset to make counnting easier
        map<int,int>mpp;
        fun(0,a,n,mpp);

        int maxi=0;
        for(auto it:mpp){
            maxi=max(maxi,it.first);
        }
        int ans=mpp[maxi];
        return ans;
    }
};