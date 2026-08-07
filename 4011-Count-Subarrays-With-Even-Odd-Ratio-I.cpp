class Solution {
public:
    int countRatioSubarrays(vector<int>& v, int a, int b) {
        int n=v.size();
        //making all subarrays then counting simply
        
        int ans=0;

        for(int i=0;i<n;i++){
            int even=0;
            int odd=0;
                for(int j=i;j<n;j++){
                    if(v[j]%2)odd++;
                    else even++;

                    if(odd!=0){
                        if(even*b<=a*odd)ans++;
                    }
                }
        }
        return ans;
    }
};