class Solution {
public:

    // bool isValid(int &i,int &j,int &k){
    //     return (i+j>k && (i!=0 && j!=0 && k!=0));
    // }

    int triangleNumber(vector<int>& v) {
        int n=v.size();
        sort(v.begin(),v.end());
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                // for(int k=j+1;k<n;k++){
                //     if(isValid(v[i],v[j],v[k])){
                //         count++;
                //     }
                // }
                //if we found v[i] and v[j] then can easily find v[k] if present by upper bound as the array is already sorted
                auto it=lower_bound(v.begin(),v.end(),v[i]+v[j])-v.begin();
                int ind=it-j-1;
                count+=max(0,ind);
            }
        }
        return count;
    }
};