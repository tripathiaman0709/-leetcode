class Solution {
public:
    int lengthOfLIS(vector<int>& v) {
        //finding the length of longeest increasing subsequence
        int n=v.size();

        // vector<int>subsequence(n,1);

        // for(int i=1;i<n;i++){
        //     for(int j=0;j<=i-1;j++){
        //         if(v[j]<v[i]){
        //             subsequence[i]=max(subsequence[i],subsequence[j]+1);
        //         }
        //     }
        // }
        // int maxi=0;
        // for(int i=0;i<n;i++){
        //     maxi=max(maxi,subsequence[i]);
        // }
        // return maxi;


        //finding using patience sorting 

        //with the use of lower bound
        //which finds the smallest number that is less than equal to the number given in the given sorted array

        vector<int>sorted;

        for(int i=0;i<n;i++){
            int num=v[i];
            auto it=lower_bound(sorted.begin(),sorted.end(),num);

            if(it==sorted.end()){
                sorted.push_back(num);
            }else{
                *it=num;
            }
        }
        return sorted.size();
    }
};