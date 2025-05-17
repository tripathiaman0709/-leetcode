class Solution {
public:
    void sortColors(vector<int>& v) {
        // int n=v.size();
        // //soving without sorting
        // vector<int>hash(3,0);
        // for(int i=0;i<n;i++){
        //     hash[v[i]]++;
        // }
        // vector<int>ans;
        // for(int i=0;i<hash[0];i++){
        //     ans.push_back(0);
        // }
        // for(int i=0;i<hash[1];i++){
        //     ans.push_back(1);
        // }
        // for(int i=0;i<hash[2];i++){
        //     ans.push_back(2);
        // }

        // v=ans;

        // sort(v.begin(),v.end());

        //doing the code in constant space complexity

        int n=v.size();
        int l=0;
        int r=n-1;
        int i=0;
        while(i<=r){
            if(v[i]==0){
                swap(v[l],v[i]);
                l++;
            }else if(v[i]==2){
                swap(v[r],v[i]);
                r--;
                i--;
            }
            i++;
        }

    }
};