class Solution {
public:
    int missingInteger(vector<int>& v) {
        int n=v.size();
        unordered_map<int,int>mpp;
        for(auto it:v){
            mpp[it]++;
        }
        //finding the longest prefix 
        int sz=1;
        for(int i=1;i<n;i++){
            if(v[i]-v[i-1]==1){
                sz++;
            }else{
                break;
            }
        }
        int sum=0;
        //now the sum of the prefix
        for(int i=0;i<sz;i++){
            sum+=v[i];
        }

        //after getting the sum
        //we will run a loop to find the smallest larger number than prefix sum

        for(int i=sum;i<sum+51;i++){
            if(mpp[i]==0){
                return i;
            }
        }

        return -1;
    }
};