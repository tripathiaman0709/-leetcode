class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& a) {
        int n=a.size();
        sort(a.begin(),a.end());

        //using tabulation method
        //coz its same as LIS

        vector<int>result;
        vector<int>lis(n,1);
        vector<int>pre(n,-1);

        int lastind=0;
        int maxl=1;



        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(a[i]%a[j]==0){
                    if(lis[i]<lis[j]+1){
                        lis[i]=lis[j]+1;
                        pre[i]=j;
                    }
                }

                if(maxl<lis[i]){
                    maxl=lis[i];
                    lastind=i;
                }
            }
        }

        while(lastind!=-1){
            result.push_back(a[lastind]);
            lastind=pre[lastind];
        }
        return result;
        
    }
};